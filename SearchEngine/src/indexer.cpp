#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

#include "indexer.h"
#include "boost/algorithm/string.hpp"


namespace indexers
{
	std::string Indexer::indexPage(const std::string& url, std::string& htmlText)
	{
		auto formattedText = formatText(htmlText);
		auto wordsCount = conutWords(formattedText);
		saveToDatabase(url, wordsCount);
		return formattedText;
	}


	std::string Indexer::formatText(std::string& text)
	{
		auto clearedText = removeHTMLTags(text);
		deleteUnicodeChars(clearedText);
		setLowercase(clearedText);
		removeNewlines(clearedText);
		removeTabs(clearedText);
		removeExtraSpaces(clearedText);
		removePunctuationMarks(clearedText);
		auto result = deleteLongWords(clearedText);
		return result;
	}


	std::string Indexer::removeHTMLTags(std::string& htmlText)
	{
		std::regex tags("<[^>]*>");
		std::string remove{};
		return std::regex_replace(htmlText, tags, remove);
	}


	void Indexer::removeTabs(std::string& text)
	{
		boost::replace_all(text, "\t", " ");
	}


	void Indexer::removeNewlines(std::string& text)
	{
		boost::replace_all(text, "\r\n", " ");
	}


	void Indexer::setLowercase(std::string& text)
	{
		boost::algorithm::to_lower(text);
	}


	void Indexer::removeExtraSpaces(std::string& text)
	{
		boost::trim(text);
		while (text.find("  ") != text.npos)
		{
			boost::replace_all(text, "  ", " ");
		}
	}


	void Indexer::removePunctuationMarks(std::string& text)
	{
		text.erase(std::remove_if(text.begin(), text.end(), ispunct), text.end());
	}


	std::string Indexer::deleteLongWords(std::string& text)
	{
		std::string result;
		std::stringstream ss(text);
		std::string word;

		while (ss >> word) {
			if (word.length() <= 32)
			{
				result = result + word + " ";
			}
		}

		return result;
	}


	WordsCount Indexer::conutWords(std::string& text)
	{
		WordsCount wordsCount;
		std::istringstream stringStream(text);
		std::string word;

		while (stringStream >> word)
		{
			wordsCount[word]++;
		}

		return wordsCount;
	}


	void Indexer::saveToDatabase(const std::string& url, WordsCount& wordsCount)
	{
		auto urlId = database.addUrl(url)[0][0].as<std::string>();

		for (const auto& pair : wordsCount)
		{
			auto word = pair.first;
			auto count = pair.second;
			auto wordId = database.addWord(word)[0][0].as<std::string>();
			database.addUrlWordCount(urlId, wordId, std::to_string(count));
		}
	}


	void Indexer::deleteUnicodeChars(std::string& text)
	{
		text.erase(std::remove_if(text.begin(), text.end(), [](char c) {return !(c >= 0 && c < 128); }), text.end());
	}
}