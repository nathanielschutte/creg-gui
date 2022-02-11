#pragma once

#include <cstdint>
#include <limits>
#include <string>

#include "Tables.h"

typedef uint8_t byte_t;
typedef uint8_t MSG_ID;


typedef void (*handler_func_t)(std::string&, byte_t*);

// [key] [bytes] *[val...]
typedef struct {
	byte_t key;
	byte_t bytes;
	byte_t* val;
} keyval_bytes_t;

// [idx] [status] [action] [bytes] *[data...]
typedef struct {
	byte_t id;
	byte_t status;
	byte_t action;
	byte_t bytes;
	keyval_bytes_t* data;
} msg_bytes_t;

class Message
{

public:

	Message();
	Message(std::string msg);
	virtual ~Message();

public:
	static MSG_ID last_id;

public:
	bool ok();
	bool from_string(std::string msg);
	std::string& to_string();

private:
	bool m_ok;
	MSG_ID m_id;
	std::string m_str;

private:
	void m_interval_str_handler(std::string& input, byte_t* output);
};

