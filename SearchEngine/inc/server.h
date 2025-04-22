#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "database.h"

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

namespace http_servers
{
    class HTTPConnection : public std::enable_shared_from_this<HTTPConnection>
    {
    public:
        HTTPConnection(tcp::socket socket, databases::SearchDatabase& database) : socket(std::move(socket)), database(database) {}

    public:
        void start();

    private:
        databases::SearchDatabase& database;
        std::string message;
        tcp::socket socket;
        beast::flat_buffer buffer{ 8192 };
        http::request<http::dynamic_body> request;
        http::response<http::dynamic_body> response;
        net::steady_timer deadline{ socket.get_executor(), std::chrono::seconds(60) };

    private:
        void readRequest();
        void processRequest();
        void createResponse();
        void writeResponse();
        void checkDeadline();
        std::vector<std::string> getSearchWords(std::string& searchQuery);
        std::string createRankedListHtml(std::vector<std::string> rankedPages);
        std::string createErrorMessageHtml(const std::string& message);
    };

    void httpServer(tcp::acceptor& acceptor, tcp::socket& socket, databases::SearchDatabase& database);
}


namespace html
{
    const std::string mainPageStyle =
        "<style>\n"
        "body {\n"
        "    background-color: #3745c2;\n"
        "}\n"
        "form {\n"
        "    background-color: #4654e1;\n"
        "    width: 1000px;\n"
        "    height: 44px;\n"
        "    border-radius: 5px;\n"
        "    display: flex;\n"
        "    flex-direction: row;\n"
        "    align-items: center;\n"
        "    margin-top: 200px;\n"
        "    margin-left: auto;\n"
        "    margin-right: auto;\n"
        "}\n"
        "input {\n"
        "    all: unset;\n"
        "    font: 16px system-ui;\n"
        "    color: #fff;\n"
        "    height: 100%;\n"
        "    width: 100%;\n"
        "    padding: 6px 10px;\n"
        "}\n"
        "::placeholder {\n"
        "    color: #fff;\n"
        "    opacity: 0.7;\n"
        "}\n"
        "svg {\n"
        "    color: #fff;\n"
        "    fill: currentColor;\n"
        "    width: 24px;\n"
        "    height: 24px;\n"
        "    padding: 10px;\n"
        "}\n"
        "button {\n"
        "    all: unset;\n"
        "    cursor: pointer;\n"
        "    width: 44px;\n"
        "    height: 44px;\n"
        "}\n"
        "ol {\n"
        "    width: 1000px;\n"
        "    padding: 0px;\n"
        "    color: white;\n"
        "    margin-left: auto;\n"
        "    margin-right: auto;\n"
        "    font: 16px system-ui;\n"
        "}\n"
        "a:link {\n"
        "    color: white;\n"
        "    background-color: transparent;\n"
        "    text-decoration: none;\n"
        "}\n"
        "a:visited {\n"
        "    color: grey;\n"
        "    background-color: transparent;\n"
        "    text-decoration: none;\n"
        "}\n"
        "a:hover {\n"
        "    color: red;\n"
        "    background-color: transparent;\n"
        "    text-decoration: none;\n"
        "}\n"
        "a:active {\n"
        "    color: green;\n"
        "    background-color: transparent;\n"
        "    text-decoration: none;\n"
        "}\n"
        "p {\n"
        "    color: white;\n"
        "    background-color: transparent;\n"
        "    text-decoration: none;\n"
        "    text-align: center;\n"
        "    font: 16px system-ui;\n"
        "}\n"
        "</style>\n";


    const std::string searchBar =
        "<form method=\"post\" role=\"search\" id=\"form\">\n"
        "    <input type=\"search\" id=\"query\" name=\"q\"\n"
        "           placeholder=\"Search...\" aria-label=\"Search through site content\">\n"
        "    <button>\n"
        "        <svg viewBox=\"0 0 1024 1024\">\n"
        "            <path class=\"path1\" d=\"M848.471 928l-263.059-263.059c-48.941 36.706-110.118 55.059-177.412 "
        "                                      55.059-171.294 0-312-140.706-312-312s140.706-312 312-312c171.294 0 312 "
        "                                      140.706 312 312 0 67.294-24.471 128.471-55.059 177.412l263.059 263.059-79.529 "
        "                                      79.529zM189.623 408.078c0 121.364 97.091 218.455 218.455 218.455s218.455-97.091 "
        "                                      218.455-218.455c0-121.364-103.159-218.455-218.455-218.455-121.364 0-218.455 97.091-218.455 218.455z\">"
        "            </path>\n"
        "        </svg>\n"
        "    </button>\n"
        "</form>\n";
}