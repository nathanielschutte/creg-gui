
// Sendable message

#include "Message.h"

MSG_ID Message::last_id = 0;

Message::Message() {

	if (last_id < UCHAR_MAX)
		m_id = last_id++;
	else {
		last_id = 0;
		m_id = last_id;
	}

	m_ok = true;
	m_str = "";
}

// Create message object from string
Message::Message(std::string msg) : Message() {
	m_ok = from_string(msg);

	m_str = msg;
}

Message::~Message() {

}

bool Message::ok() {
	return m_ok;
}

/*
 * Convert commandline string into message bytes
 * Examples:
 *	put wave=square interval=3/4
 *	putone interval=1/2
 *	get
 *	getone interval 
 */
bool Message::from_string(std::string msg) {

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

void Message::m_interval_str_handler(std::string& input, byte_t* output) {

}

std::string& Message::to_string() {
	return m_str;
}
