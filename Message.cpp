
// Sendable message

#include "Message.h"

msg_id_t Message::last_id = 0;

Message::Message() {

	if (last_id < UCHAR_MAX)
		m_id = last_id++;
	else {
		last_id = 0;
		m_id = last_id;
	}

	m_msg = new msg_bytes_t(m_id, STATUS(NONE), ACTION(PASS), 0, NULL);

	m_ok = true;
	m_str = "";
}

// Create message object from string
Message::Message(std::string& msg) : Message() {
	m_ok = from_string(msg);

	m_str = msg;
}

// Create message object from labelled bytes
Message::Message(byte_t action, keyval_bytes_t* keyvals, byte_t keyval_len) : Message() {
	m_ok = from_bytes(action, keyvals, keyval_len);

	m_str = "";
}

Message::~Message() {

}

bool Message::ok() {
	return m_ok;
}


/*
 * Convert commandline string into message bytes
 * Examples:
 *	put (all)
 *	put wave=square interval=3/4
 *	get (all)
 *	get interval 
 */
bool Message::from_string(std::string& msg) {

	std::vector<std::string> parts{};
	std::string delim = " ";

	size_t pos = 0;
	while ((pos = msg.find(delim)) != std::string::npos) {
		parts.push_back(msg.substr(0, pos));

	}

	std::string action_str = msg.substr(0, msg.find(' '));

	int8_t action_id = -1;
	for (std::string action : ACTION_TABLE) {
		action_id = 0;

		if (action.compare(msg) == 0) {
			break;
		}
	}

	if (action_id < 0) return false;

	return true;
}


/* 
* Convert labelled bytes into message structs
*/
bool Message::from_bytes(byte_t action, keyval_bytes_t* keyvals, byte_t keyval_len) {

}


/*
* Get bytes for sending
*/
const byte_t* to_byte_array() {

}


/*
* Get string representation of message
*/
std::string& Message::to_string() {
	if (m_str.empty() || m_str.length() < 1) {
		m_str = "";
	}

	return m_str;
}
