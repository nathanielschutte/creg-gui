#pragma once

#include "Message.h"

class Connection
{
public:
	Connection();
	virtual ~Connection();

public:
	bool send(Message* msg);

	Message* recv(void);
};

