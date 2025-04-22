#include <string>
#include <iostream>

#include "config.h"
#include "configparser.h"
#include "database.h"
#include "indexer.h"
#include "crawler.h"

const std::string CONFIG_FILE = "./config.ini";

int main()
{
	try
	{
		config_parsers::ConfigFileParser configParser;
		auto config = configParser.createConfigFromFile(CONFIG_FILE);

		std::cout << *config << std::endl;

		databases::ConnectionData connectionData;
		auto& databaseConfig = config->getDatabaseSettings();
		connectionData.host = databaseConfig.databaseHost;
		connectionData.port = databaseConfig.databasePort;
		connectionData.databaseName = databaseConfig.databaseName;
		connectionData.login = databaseConfig.username;
		connectionData.pass = databaseConfig.password;

		databases::SearchDatabase database(connectionData);
		crawlers::Crawler crawler(database);

		std::cout << "Starting Crawler..." << std::endl;

		auto& searchEngineSettings = config->getSearchEngineSettings();
		crawler.crawl(searchEngineSettings.startPage, stoi(searchEngineSettings.recursionDepth));
		std::cin.get();
	}
	catch (const std::exception& e)
	{
		std::cout << "Crawler error: " << e.what() << std::endl;
		std::cin.get();
	}
}