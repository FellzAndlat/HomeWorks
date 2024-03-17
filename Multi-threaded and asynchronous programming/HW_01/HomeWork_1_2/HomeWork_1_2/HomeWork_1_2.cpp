#include <iostream>
#include <vector>
#include <thread>
#include <condition_variable>
#include <random>
#include <chrono>

std::once_flag flag;

std::vector<int> randomVector(size_t size)
{
    std::vector<int> v(size);
    std::random_device r;
    std::generate(v.begin(), v.end(), [&] {return r(); });
    return v;
}
void kernel_output(int th) {
    std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;
    std::cout << th << " потоков ";
}

void vector_sum(std::vector <int> arr1, int th, int num) {
    std::call_once(flag, kernel_output, 1);
    std::vector <int> arr2 = arr1;
    auto start = std::chrono::steady_clock::now();
    for (int i = num - 1; i < arr1.size(); i += th) {
        arr2[i] = arr1[i] + arr2[i];
    }
    auto end = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    std::cout << diff.count() << "s ";
}

int main()
{
    int th = 1;
    std::vector <int> arr1(randomVector(1000));
    std::vector <int> arr2(randomVector(10000));
    std::vector <int> arr3(randomVector(100000));
    std::vector <int> arr4(randomVector(1000000));
    for (int i = 0; i < 4; ++i) {
        std::thread th1(vector_sum, arr2, th, 1);
        th1.join();
    }
}