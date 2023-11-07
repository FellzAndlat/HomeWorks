#include <iostream>
#include "Counter.h"
void Counter::add() {
    value += 1;
}
void Counter::Subtract() {
    value -= 1;
}
void Counter::print() {
    std::cout << value << "\n";
}
Counter::Counter(int value) {
    this->value = value;
}