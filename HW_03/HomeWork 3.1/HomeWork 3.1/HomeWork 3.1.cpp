#include <iostream>
#include <windows.h>

class calculator {
private:
    double num1;
    double num2;
    double num3 = 0;
public:
    bool set_num1(double num1) {
        if (num1 == 0) {
            return false;
        }
        else {
            this->num1 = num1;
            return true;
        }
    }
    bool set_num2(double num2) {
        if (num2 == 0) {
            return false;
        }
        else {
            this->num2 = num2;
            return true;
        }
    }
    double add() {
        num3 = num1 + num2;
        return num3;
    }
    double multiply() {
        num3 = num1 * num2;
        return num3;
    }
    double subtract_1_2() {
        num3 = num2 - num1;
        return num3;
    }
    double subtract_2_1() {
        num3 = num1 - num2;
        return num3;
    }
    double divide_1_2() {
        num3 = num1 / num2;
        return num3;
    }
    double divide_2_1() {
        num3 = num2 / num1;
        return num3;
    }
    calculator () {};
};

int main() {

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    calculator calculator;
    double num1, num2;

    for (;;) {
        for (;;) {
            std::cout << "Введите num1: ";
            std::cin >> num1;
            if (calculator.set_num1(num1) == true) {
                break;;
            }
            else {
                std::cout << "Не верный ввод!" << "\n";
            }
        }
        for (;;) {
            std::cout << "Введите num2: ";
            std::cin >> num2;
            if (calculator.set_num2(num2) == true) {
                break;;
            }
            else {
                std::cout << "Не верный ввод!" << "\n";
            }
        }
        std::cout << "num1 + num2 = " << calculator.add() << "\n";
        std::cout << "num1 - num2 = " << calculator.subtract_2_1() << "\n";
        std::cout << "num2 - num1 = " << calculator.subtract_1_2() << "\n";
        std::cout << "num1 * num2 = " << calculator.multiply() << "\n";
        std::cout << "num1 / num2 = " << calculator.divide_1_2() << "\n";
        std::cout << "num2 / num1 = " << calculator.divide_2_1() << "\n";
    }
    return 0;
}