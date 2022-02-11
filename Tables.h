#pragma once

// String tables and reference enums

#include <string>

typedef const std::string str_table_t;


// Message strings
enum ACTION {
	PUTONE,
	PUTMANY,
	GETONE,
	GETMANY
};
const str_table_t ACTION_TABLE[] = {
	"putone",
	"putmany",
	"getone",
	"getmany"
};


// Generated wave types
enum WAVE {
	SQUARE,
	SINE
};
const str_table_t WAVE_TABLE[] = {
	"square",
	"sine"
};


// Status codes
enum STATUS {
	OK,
	ERROR
};
const str_table_t STATUS_TABLE[] = {
	"ok",
	"err"
}
