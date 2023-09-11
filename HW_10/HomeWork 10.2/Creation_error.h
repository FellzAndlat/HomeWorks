#pragma once
#include <iostream>

class Creation_error : public std::domain_error {
private:
    std::string ex;
public:
    std::string get_error();
    Creation_error(std::string ex);
};