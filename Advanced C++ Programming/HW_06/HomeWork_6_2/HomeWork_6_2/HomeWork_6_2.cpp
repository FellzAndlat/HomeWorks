#include <iostream>
#include <set>


int main()
{
    int size;
    std::cout << "[in]: ";
    std::cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        std::cout << "[in]: ";
        std::cin >> arr[i];
    }
    std::set<int, std::greater <int> > set;
    for (int i = 0; i < size; ++i) {
        set.insert(arr[i]);
    }
    for (auto i : set) std::cout << "[out]: " << i << std::endl;
    return 0;
}