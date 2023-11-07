#include <iostream>
#include <string>
#include "Leaver.h"
#include <Windows.h>

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str;
    std::cout << "¬ведите им€: ";
    std::cin >> str;
    Leav::Leaver leaver;
    std::cout << leaver.leave(str);

}
