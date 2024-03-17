#include <iostream>
#include <vector>
#include <thread>
#include <condition_variable>
#include <random>
#include <chrono>
#include <execution>
#include <windows.h>

std::once_flag flag;

void randomVector(std::vector<int>& arr1, int size)
{
    std::mt19937 gen;
    std::uniform_int_distribution<int> dist(0, size);
    std::generate(std::execution::par, arr1.begin(), arr1.end(), [&]() {
        return dist(gen);
        });
}
void kernel_output(int th) {
    std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;
    std::cout << "           1000 " << "10000 " << "100000 " << "1000000 " << std::endl;
    std::cout << th << " поток   ";
}

void vector_sum(std::vector <int> arr1, int th, int num) {
    std::call_once(flag, kernel_output, 1);
    std::vector <int> arr2 = arr1;
    for (int i = num - 1; i < arr1.size(); i += th) {
        arr2[i] = arr1[i] + arr2[i];
    }
}
void one_thread(std::vector <int>& arr1, std::vector <int>& arr2, std::vector <int>& arr3, std::vector <int>& arr4) {
    int th = 1;
    for (int i = 0; i < 4; ++i) {
        auto start = std::chrono::system_clock::now();
        if (i == 0) {
            std::thread th1(vector_sum, arr1, th, 1);
            th1.join();
        } else if (i == 1) {
            std::thread th1(vector_sum, arr2, th, 1);
            th1.join();
        } else if (i == 2) {
            std::thread th1(vector_sum, arr3, th, 1);
            th1.join();
        } else {
            std::thread th1(vector_sum, arr4, th, 1);
            th1.join();
        }
        auto end = std::chrono::system_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << diff.count() << "ms ";
    }
    std::cout << std::endl;
}
void two_thread(std::vector <int>& arr1, std::vector <int>& arr2, std::vector <int>& arr3, std::vector <int>& arr4) {
    int th = 2;
    std::cout << th << " потоков ";
    for (int i = 0; i < 4; ++i) {
        auto start = std::chrono::system_clock::now();
        if (i == 0) {
            std::thread th1(vector_sum, arr1, th, 1);
            std::thread th2(vector_sum, arr1, th, 2);
            th1.join();
            th2.join();
        }
        else if (i == 1) {
            std::thread th1(vector_sum, arr2, th, 1);
            std::thread th2(vector_sum, arr2, th, 2);
            th1.join();
            th2.join();
        }
        else if (i == 2) {
            std::thread th1(vector_sum, arr3, th, 1);
            std::thread th2(vector_sum, arr3, th, 2);
            th1.join();
            th2.join();
        }
        else {
            std::thread th1(vector_sum, arr4, th, 1);
            std::thread th2(vector_sum, arr4, th, 2);
            th1.join();
            th2.join();
        }
        auto end = std::chrono::system_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << diff.count() << "ms ";
    }
    std::cout << std::endl;
}
void for_thread(std::vector <int>& arr1, std::vector <int>& arr2, std::vector <int>& arr3, std::vector <int>& arr4) {
    int th = 4;
    std::cout << th << " потоков ";
    for (int i = 0; i < 4; ++i) {
        auto start = std::chrono::system_clock::now();
        if (i == 0) {
            std::thread th1(vector_sum, arr1, th, 1);
            std::thread th2(vector_sum, arr1, th, 2);
            std::thread th3(vector_sum, arr1, th, 3);
            std::thread th4(vector_sum, arr1, th, 4);
            th1.join();
            th2.join();
            th3.join();
            th4.join();
        }
        else if (i == 1) {
            std::thread th1(vector_sum, arr2, th, 1);
            std::thread th2(vector_sum, arr2, th, 2);
            std::thread th3(vector_sum, arr2, th, 3);
            std::thread th4(vector_sum, arr2, th, 4);
            th1.join();
            th2.join();
            th3.join();
            th4.join();
        }
        else if (i == 2) {
            std::thread th1(vector_sum, arr3, th, 1);
            std::thread th2(vector_sum, arr3, th, 2);
            std::thread th3(vector_sum, arr3, th, 3);
            std::thread th4(vector_sum, arr3, th, 4);
            th1.join();
            th2.join();
            th3.join();
            th4.join();
        }
        else {
            std::thread th1(vector_sum, arr4, th, 1);
            std::thread th2(vector_sum, arr4, th, 2);
            std::thread th3(vector_sum, arr4, th, 3);
            std::thread th4(vector_sum, arr4, th, 4);
            th1.join();
            th2.join();
            th3.join();
            th4.join();
        }
        auto end = std::chrono::system_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << diff.count() << "ms ";
    }
    std::cout << std::endl;
}
void eight_thread(std::vector <int>& arr1, std::vector <int>& arr2, std::vector <int>& arr3, std::vector <int>& arr4) {
    int th = 8;
    std::cout << th << " потоков ";
    for (int i = 0; i < 4; ++i) {
        auto start = std::chrono::system_clock::now();
        if (i == 0) {
            std::thread th1(vector_sum, arr1, th, 1);
            std::thread th2(vector_sum, arr1, th, 2);
            std::thread th3(vector_sum, arr1, th, 3);
            std::thread th4(vector_sum, arr1, th, 4);
            std::thread th5(vector_sum, arr1, th, 5);
            std::thread th6(vector_sum, arr1, th, 6);
            std::thread th7(vector_sum, arr1, th, 7);
            std::thread th8(vector_sum, arr1, th, 8);
            th1.join();
            th2.join();
            th3.join();
            th4.join();
            th5.join();
            th6.join();
            th7.join();
            th8.join();
        }
        else if (i == 1) {
            std::thread th1(vector_sum, arr2, th, 1);
            std::thread th2(vector_sum, arr2, th, 2);
            std::thread th3(vector_sum, arr2, th, 3);
            std::thread th4(vector_sum, arr2, th, 4);
            std::thread th5(vector_sum, arr2, th, 5);
            std::thread th6(vector_sum, arr2, th, 6);
            std::thread th7(vector_sum, arr2, th, 7);
            std::thread th8(vector_sum, arr2, th, 8);
            th1.join();
            th2.join();
            th3.join();
            th4.join();
            th5.join();
            th6.join();
            th7.join();
            th8.join();
        }
        else if (i == 2) {
            std::thread th1(vector_sum, arr3, th, 1);
            std::thread th2(vector_sum, arr3, th, 2);
            std::thread th3(vector_sum, arr3, th, 3);
            std::thread th4(vector_sum, arr3, th, 4);
            std::thread th5(vector_sum, arr3, th, 5);
            std::thread th6(vector_sum, arr3, th, 6);
            std::thread th7(vector_sum, arr3, th, 7);
            std::thread th8(vector_sum, arr3, th, 8);
            th1.join();
            th2.join();
            th3.join();
            th4.join();
            th5.join();
            th6.join();
            th7.join();
            th8.join();
        }
        else {
            std::thread th1(vector_sum, arr4, th, 1);
            std::thread th2(vector_sum, arr4, th, 2);
            std::thread th3(vector_sum, arr4, th, 3);
            std::thread th4(vector_sum, arr4, th, 4);
            std::thread th5(vector_sum, arr4, th, 5);
            std::thread th6(vector_sum, arr4, th, 6);
            std::thread th7(vector_sum, arr4, th, 7);
            std::thread th8(vector_sum, arr4, th, 8);
            th1.join();
            th2.join();
            th3.join();
            th4.join();
            th5.join();
            th6.join();
            th7.join();
            th8.join();
        }
        auto end = std::chrono::system_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << diff.count() << "ms ";
    }
    std::cout << std::endl;
}
void sixteen_thread(std::vector <int>& arr1, std::vector <int>& arr2, std::vector <int>& arr3, std::vector <int>& arr4) {
    int th = 16;
    std::cout << th << " потоков ";
    for (int i = 0; i < 4; ++i) {
        auto start = std::chrono::system_clock::now();
        if (i == 0) {
            std::thread th1(vector_sum, arr1, th, 1);
            std::thread th2(vector_sum, arr1, th, 2);
            std::thread th3(vector_sum, arr1, th, 3);
            std::thread th4(vector_sum, arr1, th, 4);
            std::thread th5(vector_sum, arr1, th, 5);
            std::thread th6(vector_sum, arr1, th, 6);
            std::thread th7(vector_sum, arr1, th, 7);
            std::thread th8(vector_sum, arr1, th, 8);
            std::thread th9(vector_sum, arr1, th, 9);
            std::thread th10(vector_sum, arr1, th, 10);
            std::thread th11(vector_sum, arr1, th, 11);
            std::thread th12(vector_sum, arr1, th, 12);
            std::thread th13(vector_sum, arr1, th, 13);
            std::thread th14(vector_sum, arr1, th, 14);
            std::thread th15(vector_sum, arr1, th, 15);
            std::thread th16(vector_sum, arr1, th, 16);
            th1.join();
            th2.join();
            th3.join();
            th4.join();
            th5.join();
            th6.join();
            th7.join();
            th8.join();
            th9.join();
            th10.join();
            th11.join();
            th12.join();
            th13.join();
            th14.join();
            th15.join();
            th16.join();
        }
        else if (i == 1) {
            std::thread th1(vector_sum, arr2, th, 1);
            std::thread th2(vector_sum, arr2, th, 2);
            std::thread th3(vector_sum, arr2, th, 3);
            std::thread th4(vector_sum, arr2, th, 4);
            std::thread th5(vector_sum, arr2, th, 5);
            std::thread th6(vector_sum, arr2, th, 6);
            std::thread th7(vector_sum, arr2, th, 7);
            std::thread th8(vector_sum, arr2, th, 8);
            std::thread th9(vector_sum, arr2, th, 9);
            std::thread th10(vector_sum, arr2, th, 10);
            std::thread th11(vector_sum, arr2, th, 11);
            std::thread th12(vector_sum, arr2, th, 12);
            std::thread th13(vector_sum, arr2, th, 13);
            std::thread th14(vector_sum, arr2, th, 14);
            std::thread th15(vector_sum, arr2, th, 15);
            std::thread th16(vector_sum, arr2, th, 16);
            th1.join();
            th2.join();
            th3.join();
            th4.join();
            th5.join();
            th6.join();
            th7.join();
            th8.join();
            th9.join();
            th10.join();
            th11.join();
            th12.join();
            th13.join();
            th14.join();
            th15.join();
            th16.join();
        }
        else if (i == 2) {
            std::thread th1(vector_sum, arr3, th, 1);
            std::thread th2(vector_sum, arr3, th, 2);
            std::thread th3(vector_sum, arr3, th, 3);
            std::thread th4(vector_sum, arr3, th, 4);
            std::thread th5(vector_sum, arr3, th, 5);
            std::thread th6(vector_sum, arr3, th, 6);
            std::thread th7(vector_sum, arr3, th, 7);
            std::thread th8(vector_sum, arr3, th, 8);
            std::thread th9(vector_sum, arr3, th, 9);
            std::thread th10(vector_sum, arr3, th, 10);
            std::thread th11(vector_sum, arr3, th, 11);
            std::thread th12(vector_sum, arr3, th, 12);
            std::thread th13(vector_sum, arr3, th, 13);
            std::thread th14(vector_sum, arr3, th, 14);
            std::thread th15(vector_sum, arr3, th, 15);
            std::thread th16(vector_sum, arr3, th, 16);
            th1.join();
            th2.join();
            th3.join();
            th4.join();
            th5.join();
            th6.join();
            th7.join();
            th8.join();
            th9.join();
            th10.join();
            th11.join();
            th12.join();
            th13.join();
            th14.join();
            th15.join();
            th16.join();
        }
        else {
            std::thread th1(vector_sum, arr4, th, 1);
            std::thread th2(vector_sum, arr4, th, 2);
            std::thread th3(vector_sum, arr4, th, 3);
            std::thread th4(vector_sum, arr4, th, 4);
            std::thread th5(vector_sum, arr4, th, 5);
            std::thread th6(vector_sum, arr4, th, 6);
            std::thread th7(vector_sum, arr4, th, 7);
            std::thread th8(vector_sum, arr4, th, 8);
            std::thread th9(vector_sum, arr4, th, 9);
            std::thread th10(vector_sum, arr4, th, 10);
            std::thread th11(vector_sum, arr4, th, 11);
            std::thread th12(vector_sum, arr4, th, 12);
            std::thread th13(vector_sum, arr4, th, 13);
            std::thread th14(vector_sum, arr4, th, 14);
            std::thread th15(vector_sum, arr4, th, 15);
            std::thread th16(vector_sum, arr4, th, 16);
            th1.join();
            th2.join();
            th3.join();
            th4.join();
            th5.join();
            th6.join();
            th7.join();
            th8.join();
            th9.join();
            th10.join();
            th11.join();
            th12.join();
            th13.join();
            th14.join();
            th15.join();
            th16.join();
        }
        auto end = std::chrono::system_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << diff.count() << "ms ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size = 1000;

    std::vector <int> arr1(size);
    randomVector(arr1, size);
    size = 10000;
    std::vector <int> arr2(size);
    randomVector(arr2, size);
    size = 100000;
    std::vector <int> arr3(size);
    randomVector(arr3, size);
    size = 1000000;
    std::vector <int> arr4(size);
    randomVector(arr4, size);

    one_thread(arr1, arr2, arr3, arr4);
    two_thread(arr1, arr2, arr3, arr4);
    for_thread(arr1, arr2, arr3, arr4);
    eight_thread(arr1, arr2, arr3, arr4);
    sixteen_thread(arr1, arr2, arr3, arr4);

    return 0;
}