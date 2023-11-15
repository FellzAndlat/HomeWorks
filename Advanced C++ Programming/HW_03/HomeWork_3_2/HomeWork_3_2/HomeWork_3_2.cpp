#include <iostream>

class smart_array {
private:
    int* arr;
    int size;
    int i = 0;
public:
    smart_array& operator=(const smart_array& src) {
        delete [] arr;
        size = src.size;
        i = src.i;
        arr = new int[size];
        for (int j = 0; j < size; ++j) {
            arr[j] = src.arr[j];
        }
        return *this;
    }
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
        if (number < size) {
            return arr[number];
        }
        else {
            throw std::exception("Попытка обратиться к несуществующему элементу массива");
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

    smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;

    std::cout << arr.get_element(0) << " " << arr.get_element(1);
    
}
