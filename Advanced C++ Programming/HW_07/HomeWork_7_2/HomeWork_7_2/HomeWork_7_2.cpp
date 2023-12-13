#include <iostream>
#include <vector>
#include <list>
#include <set>

template <class type>
void print_container(type& arr) {
    for (auto i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set);
    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);
    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);
}