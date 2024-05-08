#include <iostream>
#include <mutex>
#include <thread>

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
    one.mu.lock();
    two.mu.lock();
    std::swap(one.i, two.i);
    one.mu.unlock();
    two.mu.unlock();
}
inline void swap_scoped_lock(Data& one, Data& two) noexcept {
    std::scoped_lock lock(one.mu, two.mu);
    std::swap(one.i, two.i);
}
inline void swap_unique_lock(Data& one, Data& two) noexcept {
    std::unique_lock <std::mutex> lk2(two.mu);
    std::unique_lock <std::mutex> lk1(one.mu);
    std::swap(one.i, two.i);
}

int main()
{
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