#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <vector>
#include <thread>
#include <future>
#include <atomic>
#include <chrono>
#include <windows.h>


template<typename T>
class safe_queue {
private:
    std::queue<T> queue;
    mutable std::mutex mtx;
    std::condition_variable cv;

public:
    safe_queue() = default;
    ~safe_queue() = default;

    void push(T value) {
        std::lock_guard<std::mutex> lock(mtx);
        queue.push(std::move(value));
        cv.notify_one();
    }

    void pop(T& value) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return !queue.empty(); });
        value = std::move(queue.front());
        queue.pop();
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(mtx);
        return queue.empty();
    }
};

class thread_pool {
private:
    std::vector<std::thread> threads;
    safe_queue<std::function<void()>> tasks;
    std::atomic<bool> stop;


    void work() {
        for (; !stop;) {
            std::function<void()> task;
            tasks.pop(task);
            if (task) {
                task();
            }
        }
    }

public:
    thread_pool() : stop(false) {
        unsigned int thread_count = std::thread::hardware_concurrency();
        for (unsigned int i = 0; i < thread_count; ++i) {
            threads.emplace_back(&thread_pool::work, this);
        }
    }

    ~thread_pool() {
        stop = true;
        for (std::thread& thread : threads) {
            tasks.push([] {});
        }
        for (std::thread& thread : threads) {
            if (thread.joinable()) {
                thread.join();
            }
        }
    }

    template<typename Func>
    void submit(Func task) {
        tasks.push(std::function<void()>(task));
    }
};

void test_1() {
    std::cout << "Тест 1" << std::endl;
}

void test_2() {
    std::cout << "Тест 2" << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    thread_pool pool;

    for (int i = 0; i < 5; ++i) {
        pool.submit(test_1);
        pool.submit(test_2);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));

    return 0;
}