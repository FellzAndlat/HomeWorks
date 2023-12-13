#include <iostream>
#include <vector>
#include <algorithm>

template <class type>
void sort_arr(type& arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    std::vector <int> arr = { 1,1,2,5,6,1,2,4 };

    std::cout << "[in]: ";
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    sort_arr(arr, arr.size());
    
    auto it = std::unique(arr.begin(), arr.end());
    arr.erase(it, arr.end());

    std::cout << "[out]: ";
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
}