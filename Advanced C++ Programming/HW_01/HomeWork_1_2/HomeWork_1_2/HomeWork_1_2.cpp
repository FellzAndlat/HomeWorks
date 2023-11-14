#include <iostream>
#include <variant>
#include <vector>
#include <string>
#include <typeinfo>

std::variant<int, std::string, std::vector<int>> get_variant() {
    std::srand(std::time(nullptr));
    int random_variable = std::rand() % 3;

    std::variant<int, std::string, std::vector<int>> result;
    switch (random_variable)
    {
    case 0:
        result = 5;
        break;
    case 1:
        result = "string";
        break;
    case 2:
        result = std::vector<int>{ 1, 2, 3, 4, 5 };
        break;
    default:
        break;
    }
    return result;
}

int main(){

    if (std::holds_alternative <int>(get_variant())) {
        auto result = std::get<int>(get_variant());
        std::cout << result * 2;

    }
    else if (std::holds_alternative <std::string>(get_variant())) {
        auto result = std::get<std::string>(get_variant());
        std::cout << result;
    }
    else if (std::holds_alternative <std::vector <int>>(get_variant())) {
        auto result = std::get<std::vector <int>>(get_variant());
        for (int i = 0; i < result.size(); ++i) {
            std::cout << result[i] << " ";
        }
    }
}
