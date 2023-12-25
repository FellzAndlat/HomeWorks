#include <iostream>
#include <vector>

template <class type>
void move_vectors(std::vector <type>& one, std::vector <type>& two) {
    std::vector <type> temp = std::move(one);
    one = std::move(two);
    two = std::move(temp);
}

int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    move_vectors(one, two);
    for (int i = 0; i < two.size(); ++i) {
        std::cout << two[i] << " ";
    }
}