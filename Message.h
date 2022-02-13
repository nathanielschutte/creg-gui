#pragma once

#include <cstdint>
#include <limits>
#include <string>

#include "Tables.h"

typedef uint8_t byte_t;
typedef uint8_t msg_id_t;

typedef void (*handler_func_t)(std::string&, byte_t*);


// Key-value bytes for message
// [key] [bytes] *[val...]
typedef struct keyval_bytes_struct {
	byte_t key;
	byte_t bytes;
	byte_t* val;

	keyval_bytes_struct(byte_t, byte_t, byte_t*);
} keyval_bytes_t;

keyval_bytes_struct::keyval_bytes_struct(byte_t _key, byte_t _bytes, byte_t* _val) {
	this->key = _key;
	this->bytes = _bytes;
	this->val = _val;
}

// Message bytes
// [idx] [status] [action] [bytes] *[data...]
typedef struct msg_bytes_struct {
	byte_t id;
	byte_t status;
	byte_t action;
	byte_t bytes;
	keyval_bytes_t* data;

	msg_bytes_struct(byte_t, byte_t, byte_t, byte_t, keyval_bytes_t*);
} msg_bytes_t;

msg_bytes_struct::msg_bytes_struct(byte_t _id, byte_t _status, byte_t _action, byte_t _bytes, keyval_bytes_t* _data) {
	this->id = _id;
	this->status = _status;
	this->action = _action;
	this->bytes = _bytes;
	this->data = _data;
}

class Message
{

public:

	Message();
	Message(byte_t action, keyval_bytes_t* keyvals, byte_t keyval_len);
	Message(std::string& msg);
	virtual ~Message();


public:

	// Store last ID statically for auto-increment
	static msg_id_t last_id;


public:

	// Check successful message creation status
	bool ok();

	// Create from string
	bool from_string(std::string& msg);

	// Create from labeled bytes
	bool from_bytes(byte_t action, keyval_bytes_t* keyvals, byte_t keyval_len);

	// Get string representation of Message
	std::string& to_string();

	// Get bytes representation of Message - for sending
	const byte_t* to_byte_array();


private:

	// Was instantiation ok
	bool m_ok;
	
	// Generated ID (also present in struct)
	msg_id_t m_id;

	// Main message data
	msg_bytes_t* m_msg;

	// String representation of message
	std::string m_str;
};
