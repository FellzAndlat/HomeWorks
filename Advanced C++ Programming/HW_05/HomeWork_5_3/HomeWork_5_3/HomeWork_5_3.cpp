#include <iostream>

class test {
private:
    int* arr;
    int size;
    int sum;
    int count;
public:
    test(int* mas, int size) {
        arr = mas;
        this->size = size;
    }
    void operator()() {
        for (int i = 0; i < size; ++i) {
            if (arr[i] % 3 == 0) {
                ++count;
                sum += arr[i];
            }
        }
    }
    int get_sum() {
        return sum;
    }
    int get_count() {
        return count;
    }
};

int main()
{
    int arr[6] = { 4, 1, 3, 6, 25, 54 };
    test t(arr, 6);
    t();

    for (int i = 0; i < 6; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "get_sum() = " << t.get_sum() << "\n";
    std::cout << "get_count() = " << t.get_count() << "\n";
}