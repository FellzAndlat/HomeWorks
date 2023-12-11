#include <iostream>
#include <windows.h>

template <class type>
class vector {
private:
    int siz = 0;
    int capacit = 4;
    type* arr = new type [capacit];
public:
    vector& operator = (const vector& src) {
        delete[] arr;
        siz = src.siz;
        capacit = src.capacit;
        arr = new type[capacit];
        for (int i = 0; i < capacit; ++i) {
            arr[i] = src.arr[i];
        }
        return *this;
    }
    int size() {
        return siz;
    }
    int capacity() {
        return capacit;
    }
    void push_back(type value) {
        if (siz < capacit) {
            arr[siz] = value;
            ++siz;
        }
        else {
            type* temp = new type[capacit * 2];
            for (int i = 0; i < capacit; ++i) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            capacit = capacit * 2;
            arr[siz] = value;
            ++siz;
        }
    }
    type at(int index) {
        try {
            if (index >= siz || index < 0) {
                throw std::exception("Обращение за пределы массива");
            }
            else {
                return arr[index];
            }
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
    }
    ~vector() {
        delete[] arr;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector <int> arr;
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(3);

    std::cout << arr.at(3) << " " << arr.size() << " " << arr.capacity() << std::endl;
    arr.push_back(2);
    std::cout << arr.size() << " " << arr.capacity() << std::endl;

    vector <int> arr2;

    arr = arr2;

    std::cout << arr.size();

    return 0;
}