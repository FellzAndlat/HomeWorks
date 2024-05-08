#include <iostream>
#include <thread>
#include <iomanip>
#include <windows.h>
#include <mutex>
#include <chrono>
#include <atomic>
#include <condition_variable>
#include <vector>

std::condition_variable broadcast;
std::mutex mu;
std::atomic_int broad = 1;
std::atomic_int Num = 5;

void drawRowProgress(size_t t, int N) {
    std::unique_lock <std::mutex> lk(mu);
    int Length = 22;
    char test = 178;
    int temp = 0;
    COORD position = { 0,t + 1 };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, position);
    
    if (t == 0) {
        COORD position = { 0,t };
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsole, position);
        std::cout << "# " << std::setw(6) << std::left << "ID "
            << std::setw(Length) << std::left << "ProgressBar "
            << std::setw(8) << std::left << " Time"
            << std::endl;
    }
    std::cout << t << " " << std::setw(6) << std::left << std::this_thread::get_id();

    lk.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    auto start = std::chrono::system_clock::now();

    for (int i = 0; i < 22; ++i) {

        while (broad == t) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 500));
        lk.lock();
        position.Y = t + 1;
        position.X = 8 + i;
        SetConsoleCursorPosition(hConsole, position);

        std::cout << test;
        broad = std::rand() % Num;
        if (i == 21) {
            Num - 1;
        }
        lk.unlock();
    }

    auto end = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    double time = diff.count();
    time = time / 1000;
    lk.lock();
    std::cout << " " << time << "S" << std::endl;
    lk.unlock();
}

void task() {
    int N = 5;
    std::thread* t = new std::thread[N];
    for (size_t i = 0; i < N; i++) {
        t[i] = std::thread(drawRowProgress, i, N);
    }
    for (size_t i = 0; i < N; i++) {
        t[i].join();
    }
    COORD position = { 0, 6 };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, position);
}

int main()
{
    task();
}