#pragma once

#include <string>
#include <map>

#include "database.h"

namespace indexers
{
	typedef std::map<std::string, int> WordsCount;

	class Indexer
	{
	public:
		Indexer(databases::SearchDatabase& database) : database(database) {}
		std::string indexPage(const std::string& url, std::string& htmlText);

	private:
		databases::SearchDatabase& database;

	private:
		std::string formatText(std::string& text);
		std::string removeHTMLTags(std::string& htmlText);
		void removeTabs(std::string& text);
		void removeNewlines(std::string& text);
		void setLowercase(std::string& text);
		void removeExtraSpaces(std::string& text);
		void removePunctuationMarks(std::string& text);
		WordsCount conutWords(std::string& text);
		void saveToDatabase(const std::string& url, WordsCount& wordsCount);
		void deleteUnicodeChars(std::string& text);
		std::string deleteLongWords(std::string& text);
	};
}