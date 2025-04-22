#include <boost/algorithm/string.hpp>
#include <boost/beast/http/string_body.hpp>
#include <mutex>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

#include "server.h"


namespace http_servers
{
    void HTTPConnection::start()
    {
        readRequest();
        checkDeadline();
    }


    void HTTPConnection::readRequest()
    {
        auto self = shared_from_this();

        http::async_read(
            socket,
            buffer,
            request,
            [self](beast::error_code ec,
                std::size_t bytes_transferred)
            {
                boost::ignore_unused(bytes_transferred);
                if (!ec)
                {
                    self->processRequest();
                }
            });
    }


    void HTTPConnection::processRequest()
    {
        response.version(request.version());
        response.keep_alive(false);

        switch (request.method())
        {
        case http::verb::get:
        {
            response.result(http::status::ok);
            response.set(http::field::server, "SearchEngine");
            createResponse();
            break;
        }
        case http::verb::post:
        {
            try
            {
                auto searchQuery = boost::beast::buffers_to_string(request.body().data());
                auto searchRequestWords = getSearchWords(searchQuery);

                if (searchRequestWords.empty())
                {
                    message = createErrorMessageHtml("Empty search request!");
                }
                else
                {
                    auto rankedPages = database.getRankedList(searchRequestWords);
                    message = createRankedListHtml(rankedPages);
                }
            }
            catch (const std::exception& e)
            {
                message = createErrorMessageHtml(e.what());
            }

            createResponse();
            break;
        }
        default:
            // We return responses indicating an error if we do not recognize the request method
            response.result(http::status::bad_request);
            response.set(http::field::content_type, "text/plain");
            beast::ostream(response.body())
                << "Invalid request-method '"
                << std::string(request.method_string())
                << "'";
            break;
        }

        writeResponse();
    }


    void HTTPConnection::createResponse()
    {
        if (request.method() == http::verb::post)
        {
            response.set(http::field::content_type, "text/html");
            beast::ostream(response.body())
                << "<html lang='en' class=''>\n"
                << "    <head>\n"
                << "        <meta charset='UTF-8'>\n"
                << "        <title>Search Engine</title>\n"
                << "    </head>\n"
                << "    <body>\n"
                << html::mainPageStyle
                << html::searchBar
                << message
                << "    </body>\n"
                << "</html>\n";
        }
        else
        {
            response.set(http::field::content_type, "text/html");
            beast::ostream(response.body())
                << "<html lang='en' class=''>\n"
                << "    <head>\n"
                << "        <meta charset='UTF-8'>\n"
                << "        <title>Search Engine</title>\n"
                << "    </head>\n"
                << "    <body>\n"
                << html::mainPageStyle
                << html::searchBar
                << "    </body>\n"
                << "</html>\n";
        }
    }


    void HTTPConnection::writeResponse()
    {
        auto self = shared_from_this();

        response.content_length(response.body().size());

        http::async_write(
            socket,
            response,
            [self](beast::error_code ec, std::size_t)
            {
                self->socket.shutdown(tcp::socket::shutdown_send, ec);
                self->deadline.cancel();
            });
    }


    void HTTPConnection::checkDeadline()
    {
        auto self = shared_from_this();

        deadline.async_wait(
            [self](beast::error_code ec)
            {
                if (!ec)
                {
                    // Close socket to cancel any outstanding operation
                    self->socket.close(ec);
                }
            });
    }


    std::vector<std::string> HTTPConnection::getSearchWords(std::string& searchQuery)
    {
        std::vector<std::string> res;
        searchQuery.erase(0, 2);
        boost::algorithm::split(res, searchQuery, boost::is_any_of("+"), boost::token_compress_on);

        res.erase(std::remove_if(res.begin(), res.end(), [](const std::string& str) {
            return str.empty() || std::all_of(str.begin(), str.end(), ::isspace);
            }), res.end());
        return res;
    }


    std::string HTTPConnection::createRankedListHtml(std::vector<std::string> rankedPages)
    {
        std::string result;
        if (!rankedPages.empty())
        {
            result += "<ol>\n";
            for (const auto& link : rankedPages)
            {
                result += "<li><a href=\"" + link + "\" target=\"_blank\">" + link + "</a></li>\n";
            }
            result += "</ol>\n";
        }
        else
        {
            result += "<p>Pages not found. Try another search request!</p>\n";
        }

        return result;
    }


    std::string HTTPConnection::createErrorMessageHtml(const std::string& err_message)
    {
        return "<p>" + err_message + "</p>\n";
    }


    void httpServer(tcp::acceptor& acceptor, tcp::socket& socket, databases::SearchDatabase& database)
    {
        acceptor.async_accept(socket,
            [&](beast::error_code ec)
            {
                if (!ec)
                {
                    auto httpConnection = std::make_shared<http_servers::HTTPConnection>(std::move(socket), database);
                    httpConnection->start();
                }
                httpServer(acceptor, socket, database);
            });
    }
}