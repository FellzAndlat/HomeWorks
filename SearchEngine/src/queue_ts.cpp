#include "queue_ts.h"

namespace queue_ts
{
	void LinksQueue::push(LinkLevel linkLevelPair)
	{
		std::lock_guard<std::mutex> guard(m);
		q.push(linkLevelPair);
	}


	LinkLevel LinksQueue::pop()
	{
		std::lock_guard<std::mutex> guard(m);

		if (q.empty())
		{
			return LinkLevel("", 0);
		}
		LinkLevel linkLevelPair = q.front();
		q.pop();
		return linkLevelPair;
	}


	int LinksQueue::size()
	{
		std::lock_guard<std::mutex> guard(m);
		return q.size();
	}
}