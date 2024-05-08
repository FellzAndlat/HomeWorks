#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

std::mutex mu;
std::atomic <int> count = 0;

void Client() {
    for (;;) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        mu.lock();
        if (count == 10) {
            mu.unlock();
            continue;
        }
        else {
            count += 1;
        }
        std::cout << "tr1: " << count << std::endl;
        mu.unlock();
    }
}
void Oper() {
    for (;;) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        mu.lock();
        if (count == 0) {
            mu.unlock();
            break;
        }
        else {
            --count;
        }
        std::cout << "tr2: " << count << std::endl;
        mu.unlock();
    }
}

int main() {
    std::thread client(Client);
    std::thread oper(Oper);

    client.join();
    oper.join();

    return 0;
}
