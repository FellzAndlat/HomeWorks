#include <iostream>
#include <string>
#include <Windows.h>

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str;

    std::cout << "Введите имя: ";
    std::cin >> str;
    std::cout << "Здравствуйте, " << str << "!" << '\n';
}