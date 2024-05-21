#include <iostream>
#include <mutex>
#include <thread>
#include <string>

class Data {
private:
    std::mutex mu;
    int i;
public:
    Data(int i) {
        this->i = i;
    }

    int get_i() {
        return i;
    }

    inline friend void swap_lock(Data& lhs, Data& rhs) noexcept;
    inline friend void swap_scoped_lock(Data& lhs, Data& rhs) noexcept;
    inline friend void swap_unique_lock(Data& lhs, Data& rhs) noexcept;
    
};

inline void swap_lock(Data& one, Data& two) noexcept{
    std::lock(one.mu, two.mu);
    std::lock_guard lk1(one.mu, std::adopt_lock);
    std::lock_guard lk2(two.mu, std::adopt_lock);
    std::swap(one.i, two.i);
}
inline void swap_scoped_lock(Data& one, Data& two) noexcept {
    std::scoped_lock lock(one.mu, two.mu);
    std::swap(one.i, two.i);
}
inline void swap_unique_lock(Data& one, Data& two) noexcept {
    std::unique_lock <std::mutex> lk2(two.mu, std::defer_lock);
    std::unique_lock <std::mutex> lk1(one.mu, std::defer_lock);
    std::lock(lk1, lk2);
    std::swap(one.i, two.i);
}

void you_fagot(std::string arr) {
    std::cout << arr << "\n";
}

int main()
{

    std::string temp = "Ты пидор";

    you_fagot(temp);


    Data one(5);
    Data two(3);
    std::cout << "swap lock" << std::endl;
    std::cout << one.get_i() << " " << two.get_i() << std::endl;
    swap_lock(one, two);
    std::cout << one.get_i() << " " << two.get_i() << std::endl;

    std::cout << "swap unique_lock" << std::endl;
    std::cout << one.get_i() << " " << two.get_i() << std::endl;
    swap_unique_lock(one, two);
    std::cout << one.get_i() << " " << two.get_i() << std::endl;

    std::cout << "swap scoped_lock" << std::endl;
    std::cout << one.get_i() << " " << two.get_i() << std::endl;
    swap_scoped_lock(one, two);
    std::cout << one.get_i() << " " << two.get_i() << std::endl;


}