#pragma once

#include <string>
#include <iostream>


namespace configs
{
	struct DatabaseSettings
	{
		std::string databaseHost;
		std::string databasePort;
		std::string databaseName;
		std::string username;
		std::string password;
	};

	struct SearchEngineSettings
	{
		std::string startPage;
		std::string recursionDepth;
		std::string port;
	};

	class Config
	{
	public:
		Config() {}
		Config(DatabaseSettings databaseSettings, SearchEngineSettings searchEngineSettings) : databaseSettings(databaseSettings), searchEngineSettings(searchEngineSettings) {}
		const DatabaseSettings& getDatabaseSettings() const { return databaseSettings; }
		const SearchEngineSettings& getSearchEngineSettings() const { return searchEngineSettings; }
		void setDatabaseSettings(DatabaseSettings NewDatabaseSettings) { databaseSettings = NewDatabaseSettings; }
		void setEngineSettings(SearchEngineSettings NewEngineSettings) { searchEngineSettings = NewEngineSettings; }

	private:
		DatabaseSettings databaseSettings;
		SearchEngineSettings searchEngineSettings;
	};
}

std::ostream& operator<<(std::ostream& stream, const configs::Config& config);