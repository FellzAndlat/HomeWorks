#include <iostream>
#include <windows.h>

struct address {
    std::string city{};
    std::string street{};
    int house_number{};
    int apartment_number{};
    int index{};
};

void filling_in_the_address(address& address) {
    std::cout << "Введите город: ";
    std::cin >> address.city;
    std::cout << "Введите улицу: ";
    std::cin >> address.street;
    std::cout << "Введите номер дома: ";
    std::cin >> address.house_number;
    std::cout << "Введите номер квартиры: ";
    std::cin >> address.apartment_number;
    std::cout << "Введите индекс: ";
    std::cin >> address.index;
    system("cls");
}

void address_output(address& address) {
    std::cout << "Город: " << address.city << "\n";
    std::cout << "Улица: " << address.street << "\n";
    std::cout << "Номер дома: " << address.house_number << "\n";
    std::cout << "Номер квартиры: " << address.apartment_number << "\n";
    std::cout << "Индекс: " << address.index << "\n";
}

void input_validation(address& address) {
    for (;;) {

        const int Y = 89;
        const int y = 121;
        const int N = 78;
        const int n = 110;
        char examination = 0;

        filling_in_the_address(address);

        std::cout << "Вы ввели:" << "\n";

        address_output(address);

        std::cout << "Введите Y если введенные вами данные верны, либо введите N: ";
        std::cin >> examination;

        if (examination == Y || examination == y) {
            system("cls");
            break;
        }
        system("cls");
    }
}
int main() {

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    address a1, a2;

    std::cout << "Введите первый адрес:" << "\n";

    input_validation(a1);

    std::cout << "Введите второй адрес:" << "\n";

    input_validation(a2);

    std::cout << "Первый адрес:" << "\n" << "\n";

    address_output(a1);

    std::cout << "\n" << "Второй адрес:" << "\n" << "\n";

    address_output(a2);
}