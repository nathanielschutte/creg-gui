
// Handle requests and responses - send through 'connection'

#include "Controller.h"

// Hold config state

// Request queue

// Await map

// Interpret responses

Controller::Controller() : m_conn() {
	m_config = new Config();
	m_config_lock = new Config();
}

Controller::Controller(wxListBox* out_log) : Controller() {
	m_out_log = out_log;
}

Controller::~Controller() {

	flush_queues();

	delete m_config;
	delete m_config_lock;
}

void Controller::process_msg(Message* msg) {
	if (!msg->ok()) {
		push_log("error", "could not parse message");
	}

	// Queue Message
	queue_msg(msg);
}

// Process separated bytes of a message
void Controller::process_msg_bytes(byte_t action, keyval_bytes_t* keyvals, byte_t keyval_len) {

	// Create message from bytes
	Message* msg = new Message(action, keyvals, keyval_len);
	process_msg(msg);
}

// Process string form of a message
void Controller::process_msg_str(std::string& str) {

	// Create Message from string
	Message* msg = new Message(str);
	process_msg(msg);
}

// Queue message for sending
void Controller::queue_msg(Message* msg) {
	m_req_queue.push(msg);

	// Keeping this single-threaded, driven by GUI events for now
	Message* send_msg = m_req_queue.front();
	m_conn.send(send_msg);
	m_req_queue.pop();

	push_log("request", msg->to_string());

	delete send_msg;
}

// Complete requests and awaits
void Controller::flush_queues() {

	if (!m_req_queue.empty()) {
		// flush the request queue - notify
	}

	if (!m_await_map.empty()) {
		// handle incomplete requests
	}
}


// Append entry to log
void Controller::push_log(std::string& prefix, std::string& log_entry) {
	if (m_out_log == nullptr) {
		return;
	}

	if (prefix.length() == 0) {
		m_out_log->AppendString(log_entry);
	}
	else {
		m_out_log->AppendString(prefix + ": " + log_entry);
	}
}

void Controller::push_log(const char* prefix, const char* log_entry) {
	std::string p(prefix);
	std::string e(log_entry);

	push_log(p, e);
}

void Controller::push_log(const char* prefix, std::string& log_entry) {
	std::string p(prefix);

	push_log(p, log_entry);
}
