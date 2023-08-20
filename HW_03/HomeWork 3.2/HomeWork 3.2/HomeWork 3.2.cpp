#include <iostream>
#include <string>
#include <Windows.h>

class Counter {
private:
    int value;
public:
    void add() {
        value += 1;
    }
    void Subtract() {
        value -= 1;
    }
    void print() {
        std::cout << value << "\n";
    }

    Counter(int value) {
        this->value = value;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int value = 0;
    std::string m;
    std::cout << "Вы хотите указать начальное значение счётчика ? Введите да или нет: ";
    std::cin >> m;

    if (m == "Да" || m == "да") {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> value;
    }
    Counter counter(value);

    

    for (;;) {
        m = "";
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> m;

        if (m == "+") {
            counter.add();
        }
        else if (m == "-") {
            counter.Subtract();
        }
        else if (m == "=") {
            counter.print();
        }
        else if (m == "х") {
            break;
        }
    }
    return 0;
}

