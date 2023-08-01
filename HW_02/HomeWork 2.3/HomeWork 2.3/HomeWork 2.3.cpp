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
    std::cout << "������� �����: ";
    std::cin >> address.city;
    std::cout << "������� �����: ";
    std::cin >> address.street;
    std::cout << "������� ����� ����: ";
    std::cin >> address.house_number;
    std::cout << "������� ����� ��������: ";
    std::cin >> address.apartment_number;
    std::cout << "������� ������: ";
    std::cin >> address.index;
    system("cls");
}

void address_output(address& address) {
    std::cout << "�����: " << address.city << "\n";
    std::cout << "�����: " << address.street << "\n";
    std::cout << "����� ����: " << address.house_number << "\n";
    std::cout << "����� ��������: " << address.apartment_number << "\n";
    std::cout << "������: " << address.index << "\n";
}

void input_validation(address& address) {
    for (;;) {

        const int Y = 89;
        const int y = 121;
        const int N = 78;
        const int n = 110;
        char examination = 0;

        filling_in_the_address(address);

        std::cout << "�� �����:" << "\n";

        address_output(address);

        std::cout << "������� Y ���� ��������� ���� ������ �����, ���� ������� N: ";
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

    std::cout << "������� ������ �����:" << "\n";

    input_validation(a1);

    std::cout << "������� ������ �����:" << "\n";

    input_validation(a2);

    std::cout << "������ �����:" << "\n" << "\n";

    address_output(a1);

    std::cout << "\n" << "������ �����:" << "\n" << "\n";

    address_output(a2);
}