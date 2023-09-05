#pragma once
#include <iostream>

class Creation_error : public std::domain_error {
public:
    Creation_error(std::string ex);
};