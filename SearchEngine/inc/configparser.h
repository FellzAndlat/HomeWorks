#pragma once

#include <map>
#include <string>
#include <memory>

#include "config.h"

namespace config_parsers
{
	typedef std::map<std::string, std::map<std::string, std::string>> configData_t;

	class ConfigFileParser
	{
	public:
		ConfigFileParser() {}
		std::unique_ptr<configs::Config> createConfigFromFile(const std::string& configFile);

	private:
		void processLine(std::string& line, std::string& configSection, configData_t& configData);
		std::unique_ptr<configs::Config> createConfig(configData_t& configData);
	};
}