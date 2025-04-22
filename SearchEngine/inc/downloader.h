#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/asio/ssl/error.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <regex>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;
namespace ssl = boost::asio::ssl;

namespace downloaders
{
	class BoostBeastDownloader
	{

	public:
		BoostBeastDownloader() {}
		std::string loadWebPage(const std::string& url);

	private:
		net::io_context ioc{};
		const std::regex regexURL{ "^(?:(https)://)([^/]+)(/.*)?" };

	private:
		std::string load(const std::string& host, const std::string& port, const std::string& target);
	};
}