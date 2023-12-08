#include <iostream>
#include <windows.h>

template <class type>
class vector {
private:
    int siz = 4;
    int capacit = 0;
    type* arr = new type [siz];
public:
    int size() {
        return siz;
    }
    int capacity() {
        return capacit;
    }
    void push_back(type value) {
        if (capacit < siz) {
            arr[capacit] = value;
            ++capacit;
        }
        else {
            type* temp = new type[siz * 2];
            for (int i = 0; i < siz; ++i) {
                temp[i] = arr[i];
            }
            arr = temp;
            delete[] temp;
            siz = siz * 2;
            arr[capacit] = value;
            ++capacit;
        }
    }
    type at(int index) {
        if (index >= capacit) {
            std::cout << "выход за пределы массива";
        }
        else {
            return arr[index];
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector <double> arr;
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(3);

    std::cout << arr.at(4) << arr.size() << arr.capacity() << "\n";
    arr.push_back(2);
    std::cout << arr.size();
}