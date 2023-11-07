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
    std::cout << "�� ������ ������� ��������� �������� �������� ? ������� �� ��� ���: ";
    std::cin >> m;

    if (m == "��" || m == "��") {
        std::cout << "������� ��������� �������� ��������: ";
        std::cin >> value;
    }
    Counter counter(value);

    

    for (;;) {
        m = "";
        std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
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
        else if (m == "�") {
            break;
        }
    }
    return 0;
}

