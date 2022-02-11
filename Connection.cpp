#include "Connection.h"

// Handle open COM serial connection

// Send and receive data

Connection::Connection() {

}

Connection::~Connection() {

}

bool Connection::send(Message* msg) {
	return true;
}

Message* Connection::recv(void) {
	return nullptr;
}
