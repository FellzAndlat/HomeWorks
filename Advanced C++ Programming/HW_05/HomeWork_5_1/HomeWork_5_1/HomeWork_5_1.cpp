#include <iostream>
#include <vector>

template <class t>
t squaring(t num) {
    num = num * num;
    return num;
}
template <class v>
std::vector <v> squaring(std::vector <v>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = arr[i] * arr[i];
    }
    return arr;
}
int main() {
    int test = 4;
    std::vector <int> test_v;
    test_v.push_back(7);
    test_v.push_back(2);
    test_v.push_back(8);
    test_v.push_back(3);
    std::cout << "[in]: " << test << "\n";
    std::cout << "[out]: " << squaring(test) << "\n";

    std::cout << "[in]: ";
    for (int i = 0; i < test_v.size(); ++i) {
        std::cout << test_v[i] << " ";
    }
    std::cout << "\n";

    test_v = squaring(test_v);

    std::cout << "[out]: ";
    for (int i = 0; i < test_v.size(); ++i) {
        std::cout << test_v[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
