#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <map>
#include <vector>
#include <stdlib.h>
#include "consts.h"


class ini_parser {
private:
    std::fstream ini;
    struct data {
        std::string section;
        std::map <std::string, std::string> value;
        data(std::string section, std::string name, std::string value) {
            this->section = section;
            this->value[name] = value;
        }
    };
    std::vector <data> arr;
    void Grammar_processing() {
        std::string str, section, name, value;
        for (; ini.eof() == false;) {
            str.clear();
            std::getline(ini, str);
            int temp = 0;
            for (int i = 0; i < str.size(); ++i) {
                if (str[i] == Consts::squareBracketCharacter) {
                    section.clear();
                    section = str;
                    section.erase(0, 1);
                    section.erase(section.size() - 1, 1);
                    break;
                }
                else if (str[i] == Consts::semicolonSymbol) {
                    break;
                }
                else if (str[i] == Consts::isEqualSymbol) {
                    name.clear();
                    value.clear();
                    name = str;
                    name.erase(i, name.size() - i);
                    value = str;
                    value.erase(0, i + 1);
                    for (int j = 0; j < value.size(); ++j) {
                        if (value[j] == Consts::semicolonSymbol) {
                            value.erase(j, value.size() - j);
                            break;
                        }
                    }
                    break;
                }
            }
            if (section.empty() == false && name.empty() == false && value.empty() == false) {
                Filling_storage(section, name, value);
            }
        }
    }

    void Filling_storage(std::string& section, std::string& name, std::string& value) {
        if (arr.empty() == true) {
            arr.push_back(data(section, name, value));
        }
        else {
            for (int i = 0; i < arr.size(); ++i) {
                if (arr[i].section == section) {
                    arr[i].value[name] = value;
                    break;
                }
                else if (i == arr.size() - 1) {
                    arr.push_back(data(section, name, value));
                }
            }
        }
    }
    void test_file() {
        try {
            if (ini.is_open()) {}
            else {
                throw std::runtime_error("Неверное имя файла");
            }
        }
        catch (const std::runtime_error& ex) {
            std::cout << ex.what() << std::endl;
        }
    }

public:
    ini_parser(const std::string&& name_file) {
        ini.open(name_file);
        test_file();
        Grammar_processing();
    }
    ini_parser() = delete;

    template <typename T>
    T get_value(std::string section_name) {
        std::string section, name;
        T value;
        for (int i = 0; i < section_name.size(); ++i) {
            if (section_name[i] == Consts::dotSymbol) {
                section = section_name;
                section.erase(i, section.size() - i);
                name = section_name;
                name.erase(0, i + 1);
                break;
            }
        }
        try {
            for (int i = 0; i < arr.size(); ++i) {
                if (arr[i].section == section) {
                    if (arr[i].value[name].empty()) {
                        throw std::runtime_error("Проверьте правильность написании имени переменной");
                    }
                    if constexpr (std::is_same_v<T, std::string>) {
                        return T{ arr[i].value[name] };
                    }
                    else if ( typeid(T).name() == typeid(int).name()) {
                        value = std::stoi(arr[i].value[name]);
                        return value;
                    }
                    else if (typeid(T).name() == typeid(double).name()) {
                        value = std::stod(arr[i].value[name]);
                        return value;
                    }
                    return 0;
                }
                else if (i == arr.size() - 1){
                    throw std::runtime_error("Проверьте правильность написании секции");
                }
            }
        }
        catch (const std::runtime_error& ex) {
            std::cout << ex.what() << std::endl;
        }
    }
    ~ini_parser() = default;
};

int main() {

    ini_parser parser("src.ini");

    auto value1 = parser.get_value<int>("Section2.var1");
    auto value2 = parser.get_value<double>("Section1.var1");
    auto value3 = parser.get_value<std::string>("Section2.var2");
    std::cout << value1 << " " << value2 << std::endl;
    std::cout << value3;

    return 0;
}
