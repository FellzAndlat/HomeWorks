#include <iostream>
#include <string>
#include <Windows.h>

class forbidden_length : public std::exception {
public:
    const char* what() const override {
        return "�� ����� ����� ��������� �����! �� ��������";
    }
};

void print(std::string word, int x) {
    if (word.size() == 5) {
        throw forbidden_length();
    }
    std::cout << "����� ����� '" << word << "' ����� " << word.size() << '\n';
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string word;
    int x = 0;
    std::cout << "������� ��������� �����: ";
    std::cin >> x;

    for (;;) {
        std::cout << "������� �����: ";
        std::cin >> word;
        try {
            print(word, x);
        }
        catch (const forbidden_length& ex) {
            std::cout << ex.what() << '\n';
            break;
        }
        catch ( ... ) {
            std::cout << "����������� ������" << '\n';
            break;
        }
        
    }
    
    return 0;
}
