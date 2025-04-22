#pragma once

#include <queue>
#include <mutex>
#include <string>

namespace queue_ts
{
	struct LinkLevel
	{
		LinkLevel(std::string link, int level) : link(link), level(level) {}
		std::string link;
		int level;
	};

	class LinksQueue
	{
	public:
		void push(LinkLevel linkLevelPair);
		LinkLevel pop();
		int size();

	private:
		std::queue<LinkLevel> q;
		std::mutex m;
	};
}