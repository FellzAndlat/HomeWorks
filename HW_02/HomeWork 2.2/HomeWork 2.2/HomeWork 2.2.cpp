#include <iostream>
#include <windows.h>

struct check {
    std::string name;
    int namber_check;
    double balance;
};

void new_balance(check& check) {
    std::cout << "������� ����� ������: ";
    std::cin >> check.balance;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    check p;

    std::cout << "������� ����� �����: ";
    std::cin >> p.namber_check;
    std::cout << "������� ��� ���������: ";
    std::cin >> p.name;
    std::cout << "������� ������: ";
    std::cin >> p.balance;

    new_balance(p);

    std::cout << "��� ����: " << p.name << ", " << p.namber_check << ", " << p.balance;

    return 0;
}
