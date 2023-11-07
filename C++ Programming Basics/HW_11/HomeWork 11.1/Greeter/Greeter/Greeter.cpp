#include "Greeter.h"

std::string Greeter::greet(std::string str2) {
    std::string str1 = "Здравствуйте, ";
    str1 = str1 + str2 + "!";
    return str1;
}
Greeter::Greeter() {};
