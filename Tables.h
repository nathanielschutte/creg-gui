#pragma once

// String tables and reference enums

#include <string>
#include <vector>


typedef std::vector<std::string> str_table_t;


// Message strings ==============================
enum ACTION {
	PASS,
	PUT,
	GET
};
const str_table_t ACTION_TABLE = {
	""
	"put",
	"get"
};
// ==============================================



// Param names
enum PARAM {
	INTERVAL,
	WAVE
};
const str_table_t PARAM_TABLE = {
	"interval",
	"wave"
};
// ==============================================



// Generated wave types =========================
enum WAVE {
	SQUARE,
	SINE
};
const str_table_t WAVE_TABLE = {
	"square",
	"sine"
};
// ==============================================



// Status codes =================================
enum STATUS {
	NONE,
	OK,
	ERR
};
const str_table_t STATUS_TABLE = {
	""
	"ok",
	"err"
};
// ==============================================
