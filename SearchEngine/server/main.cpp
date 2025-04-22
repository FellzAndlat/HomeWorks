#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <string>
#include <iostream>

#include "server.h"
#include "config.h"
#include "configparser.h"
#include "database.h"

namespace beast = boost::beast;
namespace http = beast::http;
namespace asio = boost::asio;
using tcp = asio::ip::tcp;

const std::string CONFIG_FILE = "./config.ini";
const std::string SERVER_HOST = "127.0.0.1";

int main()
{
	try
	{
		config_parsers::ConfigFileParser configParser;
		auto config = configParser.createConfigFromFile(CONFIG_FILE);

		std::cout << *config << std::endl;

		databases::ConnectionData connectionData;
		auto databaseConfig = config->getDatabaseSettings();
		connectionData.host = databaseConfig.databaseHost;
		connectionData.port = databaseConfig.databasePort;
		connectionData.databaseName = databaseConfig.databaseName;
		connectionData.login = databaseConfig.username;
		connectionData.pass = databaseConfig.password;

		databases::SearchDatabase database(connectionData);

		net::io_context serverIoc{ 1 };
		tcp::socket socket{ serverIoc };

		auto const address = net::ip::make_address(SERVER_HOST);
		auto searchEngineSettings = config->getSearchEngineSettings();
		auto serverPort = std::stoul(searchEngineSettings.port);
		tcp::endpoint ep{ address,  static_cast<boost::asio::ip::port_type>(serverPort) };

		tcp::acceptor acceptor{ serverIoc, ep };;

		std::cout << "Search server is running."
			<< " Host: " << address
			<< " Port: " << serverPort
			<< std::endl;

		http_servers::httpServer(acceptor, socket, database);
		serverIoc.run();
	}
	catch (const std::exception& e)
	{
		std::cout << "Error while starting server: " << e.what() << std::endl;
		std::cin.get();
	}
}