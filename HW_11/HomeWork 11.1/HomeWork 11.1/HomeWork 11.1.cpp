#include <iostream>
#include <string>
#include "Greeter.h"
#include <Windows.h>

int main(){
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str;
    std::cout << "¬ведите им€: ";
    std::cin >> str;
    Greeter greeter;
    std::cout << greeter.greet(str);
}
