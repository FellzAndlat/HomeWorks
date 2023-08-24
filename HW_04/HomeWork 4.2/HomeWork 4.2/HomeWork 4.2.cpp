#include <iostream>
#include <fstream>
#include <cstring>
#include <Windows.h>

class address {
private:
    std::string city;
    std::string street;
    int home;
    int apartments;
    std::string str;
public:
    void sort(address* all_add, int quantity) {
        address temp;
        for (int i = 0; i < quantity - 1; i++) {
            for (int j = 0; j < quantity - i - 1; j++) {
                if (all_add[j].city < all_add[j + 1].city) {
                    temp = all_add[j];
                    all_add[j] = all_add[j + 1];
                    all_add[j + 1] = temp;
                }
            }
        }
    }
    void conclusion(std::ofstream& fout) {
        fout << city << ", " << street << ", " << home << ", " << apartments << '\n';
    }
    address() {
        city = street = str = "";
        home = apartments = 0;
    }
    address(std::ifstream& file) {
        file >> city;
        file >> street;
        file >> home;
        file >> apartments;
    }
};


int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream file;
    file.open("in.txt");
    std::ofstream fout;
    fout.open("out.txt");
    int quantity = 0;

    if (file.is_open() == true) {
        file >> quantity;
    }
    else {
        std::cout << "Не удалось открыть файл in.txt";
    }
    address* all_add = new address[quantity];

    fout << quantity << '\n';

    for (int i = 0; i < quantity; ++i) {
        all_add[i] = address(file);
    }

    all_add->sort(all_add, quantity);

    for (int i = quantity - 1; i >= 0; --i) {
        all_add[i].conclusion(fout);
    }

    file.close();
    fout.close();
    delete[] all_add;

}