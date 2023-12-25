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
        if (this != &src) {
            delete[] arr;
            siz = src.siz;
            capacit = src.capacit;
            arr = new type[capacit];
            for (int i = 0; i < capacit; ++i) {
                arr[i] = src.arr[i];
            }
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
                throw std::runtime_error("Обращение за пределы массива");
            }
            else {
                return arr[index];
            }
        }
        catch (const std::runtime_error& ex) {
            std::cout << ex.what() << std::endl;
        }
    }
    vector() {}
    vector(const vector& src) {
        siz = src.siz;
        capacit = src.capacit;
        arr = new type[capacit];
        for (int i = 0; i < capacit; ++i) {
            arr[i] = src.arr[i];
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

    std::cout << arr.at(-1) << " " << arr.size() << " " << arr.capacity() << std::endl;
    arr.push_back(2);
    std::cout << arr.size() << " " << arr.capacity() << std::endl;

    vector <int> arr2;

    vector <int> arr3(arr);

    arr = arr2;

    std::cout << arr.size() << std::endl;

    std::cout << arr3.at(1) << " " << arr3.size() << " " << arr3.capacity() << std::endl;

    return 0;
}