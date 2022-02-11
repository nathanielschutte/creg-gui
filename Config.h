#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include <unordered_map>

typedef std::string CONFIG_KEY_T;
typedef std::string CONFIG_VAL_T;


class Config {
public:
	Config();
	Config(std::string& pathname);
	virtual ~Config();

public:

	bool read_config(std::string& pathname);
	bool write_config();
	
	CONFIG_VAL_T get(CONFIG_KEY_T& key);
	int get_int(CONFIG_KEY_T& key);
	bool get_bool(CONFIG_KEY_T& key);

private:

	std::unordered_map<CONFIG_KEY_T, CONFIG_VAL_T> m_config_map;

	std::string m_pathname;

private:

	void store_pair(CONFIG_KEY_T key, CONFIG_VAL_T val);
};
