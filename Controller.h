#pragma once

#include "wx/wx.h"

#include "Message.h"
#include "Config.h"
#include "Connection.h"

#include <queue>
#include <unordered_map>
#include <string>


class Controller
{
public:
	Controller();
	Controller(wxListBox* out_log);
	virtual ~Controller();

public:

	void process_msg_str(std::string& msg);

	void queue_msg(Message* msg);

	void flush_queues();

private:

	Connection m_conn;

	std::queue<Message*> m_req_queue;
	std::unordered_map<MSG_ID, Message*> m_await_map;

	Config* m_config;			// the current state of config
	Config* m_config_lock;		// locked config guaranteed to mirror the microcontroller's

	wxListBox* m_out_log = nullptr;

private:

	void push_log(std::string& prefix, std::string& log_entry);
	void push_log(const char* prefix, const char* log_entry);
	void push_log(const char* prefix, std::string& log_entr);
};

