#include "downloader.h"

namespace downloaders
{
	std::string BoostBeastDownloader::loadWebPage(const std::string& url)
	{
		std::smatch matchResult;
		if (!std::regex_match(url, matchResult, regexURL))
		{
			throw std::domain_error("URL: '" + url + "' is not match HTTPS protocol format!");
		}

		const std::string host = matchResult[2].str();
		const std::string target = matchResult[3].length() == 0 ? "/" : matchResult[3].str();
		std::string port;

		if (matchResult[1].str() == "https")
		{
			port = "443";
			return load(host, port, target);
		}

		return "";
	}


	std::string BoostBeastDownloader::load(const std::string& host, const std::string& port, const std::string& target)
	{
		const int version = 11;

		ssl::context ctx{ ssl::context::sslv23_client };
		ssl::stream<tcp::socket> stream(ioc, ctx);

		tcp::resolver resolver(ioc);
		auto const results = resolver.resolve(host, port);

		net::connect(stream.next_layer(), results.begin(), results.end());
		SSL_set_tlsext_host_name(stream.native_handle(), host.c_str());
		stream.handshake(ssl::stream_base::client);

		http::request<http::string_body> req{ http::verb::get, target, version };
		req.set(http::field::host, host);
		req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

		http::write(stream, req);

		beast::flat_buffer buffer;
		http::response<http::dynamic_body> res;

		http::read(stream, buffer, res);

		beast::error_code ec;
		stream.shutdown(ec);

		return boost::beast::buffers_to_string(res.body().data());
	}
}