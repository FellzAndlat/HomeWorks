#include <iostream>
#include <vector>
#include <future>

void search(std::vector<int> arr, int i, std::promise<int> value) {
    int min = i;
    for (int j = i; j < arr.size(); ++j) {
        if (arr[min] > arr[j]) {
            min = j;
        }
    }
    value.set_value(min);
}

int main()
{
    std::vector <int> arr = { 10, 234, 2, 56, 14, 67, 678, 23, 657, 3, 67, 2145, 2341 ,567 };
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int temp = 0;
    for (int i = 0; i < arr.size(); ++i) {
        std::promise <int> min_value;
        std::future<int> ft_res = min_value.get_future();
        auto ft = std::async(search, arr, i, std::move(min_value));
        int min = ft_res.get();
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
}