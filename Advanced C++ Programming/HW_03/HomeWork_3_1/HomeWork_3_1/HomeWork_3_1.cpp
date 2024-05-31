#include <iostream>

class smart_array {
private:
    int* arr;
    int size;
    int i = 0;
public:
    void add_element(int num) {
        if (i < size) {
            arr[i] = num;
            i += 1;
        }
        else {
            throw std::exception("Выход за пределы заданного массива");
        }
    }
    int get_element(int number) {
        if (number < size && number >= 0) {
            return arr[number];
        }
        else {
        }
    }
    smart_array(int size) {
        arr = new int[size];
        this->size = size;
    }
    ~smart_array() {
        delete arr;
    }
};


int main() {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        printf(arr.get_element(-1));


    return 0;
}