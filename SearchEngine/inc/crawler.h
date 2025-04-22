#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>

#include <string>
#include <vector>
#include <regex>
#include <unordered_set>
#include <mutex>

#include "queue_ts.h"
#include "downloader.h"
#include "indexer.h"
#include "database.h"


namespace crawlers
{
	class Crawler
	{
	public:
		Crawler(databases::SearchDatabase& database) : indexer(database) {}
		void crawl(std::string startUrl, int depth);
		void crawlWebPage(std::string url, int pageLevel);
		std::vector<std::string> findLinks(std::string const& htmlBody);

	private:
		tcp::socket* socket = nullptr;
		tcp::acceptor* acceptor = nullptr;
		tcp::endpoint* ep = nullptr;
		std::mutex m;
		int workingThreads = 0;
		const int maxThreads = 4;
		queue_ts::LinksQueue linksQueue;
		std::unordered_set<std::string> downloadedLinks;
		downloaders::BoostBeastDownloader downloader;
		indexers::Indexer indexer;

	private:
		void startNewThread();
		void linksToAbsolute(std::string const& parentUrl, std::vector<std::string>& foundLinks);
	};
}