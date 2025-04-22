#include "config.h"

std::ostream& operator<<(std::ostream& stream, const configs::Config& config)
{
	auto& databaseSettings = config.getDatabaseSettings();
	auto& searchEngineSettings = config.getSearchEngineSettings();

	return stream
		<< "Configuration:\n"
		<< "Database Host: " << databaseSettings.databaseHost << std::endl
		<< "Database Port: " << databaseSettings.databasePort << std::endl
		<< "Database Name: " << databaseSettings.databaseName << std::endl
		<< "User: " << databaseSettings.username << std::endl
		<< "Password: " << databaseSettings.password << std::endl
		<< "Start Page: " << searchEngineSettings.startPage << std::endl
		<< "Recursion Depth: " << searchEngineSettings.recursionDepth << std::endl
		<< "Port: " << searchEngineSettings.port << std::endl << std::endl;
}