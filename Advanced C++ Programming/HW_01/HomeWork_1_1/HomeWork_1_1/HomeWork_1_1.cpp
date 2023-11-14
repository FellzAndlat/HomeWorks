#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector <int> arr{ 4, 7, 9, 14, 12 };

    std::cout << "Входные данные: ";
    std::for_each(
        arr.begin(), arr.end(),
        [](int i) {
            std::cout << i << " ";
        }
    );
    std::cout << "\n";

    std::for_each(
        arr.begin(), arr.end(),
        [](int& i) {
            if (i % 2) {
                i = i * 3;
            }
        }
    );

    std::cout << "Выходные данные: ";
    std::for_each(
        arr.begin(), arr.end(),
        [](int i) {
            std::cout << i << " ";
        }
    );
    std::cout << "\n";

    return 0;
}