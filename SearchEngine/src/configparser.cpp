#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <stdexcept>

#include "configparser.h"

namespace config_parsers
{
    std::unique_ptr<configs::Config> ConfigFileParser::createConfigFromFile(const std::string& configFile)
    {
        std::ifstream file(configFile);
        config_parsers::configData_t configData;
        std::string currentSection;
        std::string line;

        if (!file.is_open())
        {
            throw std::runtime_error("Could not open configuration file: " + configFile);
        }

        while (std::getline(file, line))
        {
            processLine(line, currentSection, configData);
        }

        return createConfig(configData);
    }


    void ConfigFileParser::processLine(std::string& line, std::string& configSection, configData_t& configData)
    {
        if (line.empty() || line[0] == ';')
        {
            return;
        }

        if (line[0] == '[' && line.back() == ']')
        {
            configSection = line.substr(1, line.size() - 2);
        }
        else
        {
            auto equalsPos = line.find('=');
            if (equalsPos != std::string::npos)
            {
                auto key = line.substr(0, equalsPos);
                auto value = line.substr(equalsPos + 1);
                configData[configSection][key] = value;
            }
        }
    }


    std::unique_ptr<configs::Config> ConfigFileParser::createConfig(configData_t& configData)
    {
        std::string section;
        std::string parameter;

        try
        {
            configs::DatabaseSettings databaseSettings;
            section = "database";
            const auto& databaseSection = configData.at(section);

            parameter = "host";
            databaseSettings.databaseHost = databaseSection.at(parameter);

            parameter = "port";
            databaseSettings.databasePort = databaseSection.at(parameter);

            parameter = "name";
            databaseSettings.databaseName = databaseSection.at(parameter);

            parameter = "username";
            databaseSettings.username = databaseSection.at(parameter);

            parameter = "password";
            databaseSettings.password = databaseSection.at(parameter);

            configs::SearchEngineSettings searchEngineSettings;
            section = "settings";
            const auto& settingsSection = configData.at(section);

            parameter = "recursiondepth";
            searchEngineSettings.recursionDepth = settingsSection.at(parameter);

            parameter = "startpage";
            searchEngineSettings.startPage = settingsSection.at(parameter);

            parameter = "port";
            searchEngineSettings.port = settingsSection.at(parameter);

            return std::make_unique<configs::Config>(databaseSettings, searchEngineSettings);
        }
        catch (std::out_of_range)
        {
            throw std::runtime_error
            ("Config section '" + section + "' or required parameter '" + parameter + "' is missing.");
        }
    }
}