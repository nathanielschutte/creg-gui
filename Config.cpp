
#include "Config.h"

Config::Config(std::string& pathname) {
	read_config(pathname);
}

Config::Config() {

}

Config::~Config() {

}

// Load config
bool Config::read_config(std::string& pathname) {
	std::fstream file(pathname);

	if (!file) {
		return false;
	}

	std::string line;
	while (std::getline(file, line)) {
		std::istringstream iss(line);

		std::string key;
		if (std::getline(iss, key, '=')) {

			std::string value;
			if (std::getline(iss, value)) {
				store_pair(key, value);
			}
		}
	}

	return true;
}

// Get val as string
CONFIG_VAL_T Config::get(CONFIG_KEY_T& key) {
	return "";
}

// Get val as integer
int Config::get_int(CONFIG_KEY_T& key) {
	return 0;
}

// Get value as bool
bool Config::get_bool(CONFIG_KEY_T& key) {
	return true;
}

// Store a key value pair
void Config::store_pair(CONFIG_KEY_T key, CONFIG_VAL_T val) {
	m_config_map.insert(std::pair<CONFIG_KEY_T, CONFIG_VAL_T>{key, val});
}