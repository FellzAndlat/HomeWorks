#include <iostream>
#include <string>
#include <map>

int main()
{
	std::string str = {"Hello World!!"};

	std::cout << "[in]: " << str << std::endl;


	std::multimap <int, char, std::greater <int>> list;

	for (int i = 0; i < str.size(); ++i) {
		int temp = 1;
		bool flag = 0;
		for (int t = 0; t < str.size(); ++t) {
			if (i == t) {
				continue;
			}
			else if (t < i && str[i] == str[t]) {
				flag = 1;
				break;
			}
			else if (str[i] == str[t]) {
				++temp;
			}
		}
		if (flag != 1) {
			list.insert(std::pair<int, char>(temp, str[i]));
		}
	}

	std::cout << "[out]: \n";

	for (const auto& element : list) {
		std::cout << element.second << ":" << "\t" << element.first << std::endl;
	}
}