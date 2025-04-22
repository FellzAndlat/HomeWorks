#include <iostream>

#include <vector>
#include <regex>
#include <thread>
#include <mutex>
#include <algorithm>

#include "crawler.h"
#include "queue_ts.h"
#include "downloader.h"


namespace crawlers
{
	void Crawler::crawl(std::string startUrl, int depth)
	{
		if (depth <= 0) throw std::invalid_argument("Recursion depth parameter is negative!");

		linksQueue.push({ startUrl, depth });

		for (;;)
		{
			if (linksQueue.size() != 0)
			{
				if (workingThreads < maxThreads)
				{
					startNewThread();
				}
			}
			else if (workingThreads == 0)
			{
				break;
			}
		}

		m.lock();
		std::cout << "\nCrawling finished!\n";
		m.unlock();
	}


	void Crawler::startNewThread()
	{
		auto linkLevelPair = linksQueue.pop();
		auto currentUrl = linkLevelPair.link;
		auto pageLevel = linkLevelPair.level;

		if (downloadedLinks.count(currentUrl) == 0)
		{
			std::thread(&Crawler::crawlWebPage, this, currentUrl, pageLevel).detach();
			workingThreads++;
		}
	}


	void Crawler::linksToAbsolute(std::string const& parentUrl, std::vector<std::string>& foundLinks)
	{
		std::smatch matchResult;
		std::regex  protocolRelativeRegex{ "^[^/]+" };
		std::regex  hostRelativeRegex{ "^[^/]+//[^/]+" };
		std::regex  anchorLinkRegex{ "(?:[^/]+/)+[^/]+" };

		for (auto& link : foundLinks)
		{
			if (link.find("//") == 0) // relatively to protocol
			{
				std::regex_search(parentUrl, matchResult, protocolRelativeRegex);
				link = matchResult.str() + link;
			}
			else if (link.find('/') == 0) // relatively to host name
			{
				std::regex_search(parentUrl, matchResult, hostRelativeRegex);
				link = matchResult.str() + link;
			}
			else if (link.find("../") == 0) // ralatively to parent directory
			{
				int ind = std::string::npos;
				int cnt = (link.rfind("../") + 3) / 3;
				for (int i = 0; i < cnt + 1; ++i)
				{
					ind = parentUrl.rfind('/', ind - 1);
				}
				link = std::string{ parentUrl.begin(), parentUrl.begin() + ind + 1 } + std::string{ link.begin() + cnt * 3, link.end() };
			}
			else if (std::regex_match(link, anchorLinkRegex) || (link.find("#") == 0)) // anchor link
			{
				link = " ";
			}
		}

		foundLinks.erase(std::remove(foundLinks.begin(), foundLinks.end(), " "), foundLinks.end());
	}


	std::vector<std::string> Crawler::findLinks(std::string const& htmlBody)
	{
		const std::regex regexURL(R"!!(<\s*A\s+[^>]*href\s*=\s*"([^"]*)")!!", std::regex::icase);
		std::vector<std::string> links;

		std::copy(std::sregex_token_iterator(htmlBody.begin(), htmlBody.end(), regexURL, 1),
			std::sregex_token_iterator(),
			std::back_inserter(links));

		return links;
	}


	void Crawler::crawlWebPage(std::string url, int pageLevel)
	{
		try
		{
			auto htmlText = downloader.loadWebPage(url);

			if (pageLevel - 1 != 0)
			{
				auto foundedLinks = findLinks(htmlText);
				linksToAbsolute(url, foundedLinks);

				m.lock();
				std::cout << "Links added: " << foundedLinks.size() << std::endl;
				m.unlock();

				for (auto& link : foundedLinks)
				{
					if (downloadedLinks.count(link) == 0)
					{
						linksQueue.push({ link, pageLevel - 1 });
					}
				}
			}

			m.lock();
			indexer.indexPage(url, htmlText);
			downloadedLinks.insert(url);
			workingThreads--;

			std::cout
				<< "Link crawled: " << url
				<< " Level: " << pageLevel
				<< " Working threads: " << workingThreads
				<< " Links to crawl: " << linksQueue.size()
				<< std::endl;

			m.unlock();
		}
		catch (std::exception& e)
		{
			m.lock();
			std::cout << "Error while crawling webpage: '" << url << "' " << e.what() << std::endl;
			workingThreads--;
			m.unlock();
		}
	}
}