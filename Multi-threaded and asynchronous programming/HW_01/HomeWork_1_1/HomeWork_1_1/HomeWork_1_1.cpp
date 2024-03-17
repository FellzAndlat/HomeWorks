#include <iostream>
#include <thread>

int i = 0;

void Client() {
    for (;;) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (i == 10) {
            continue;
        }
        else {
            ++i;
        }
        std::cout << "tr1: " << i << std::endl;
    }
}
void Oper() {
    for (;;) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (i == 0) {
            break;
        }
        else {
            --i;
        }
        std::cout << "tr2: " << i << std::endl;
    }
}

int main() {
    std::thread client(Client);
    std::thread oper(Oper);

    client.join();
    oper.join();
     
    return 0;
}
