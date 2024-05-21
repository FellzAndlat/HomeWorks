#include <iostream>
#include <future>
#include <algorithm>
#include <array>
#include <numeric>
#include <vector>

void print(int a) {
    std::cout << a + 2 << std::endl;
}

template <typename It, typename Fu>
void foreach(It begin, It end, Fu&& function) {
    const size_t block_size = 4;
    size_t diff = static_cast<size_t>(std::distance(begin, end));

    if (diff > 0)
    {
        size_t size = diff;

        if (diff > block_size)
        {
            size = size / 2;
            It endAs = begin + size;
            std::future<void> q = std::async(std::launch::async, [begin, endAs, function]
                { foreach(begin, endAs, function); });

            q.wait();
            foreach(endAs, end, function);
        }
        else
        {
            std::for_each(begin, end, function);
        }
    }
}
int main() {
    std::vector<int> V = { 0, 1, 2, 3 };
    foreach(V.begin(), V.end(), print);
    return 0;
}