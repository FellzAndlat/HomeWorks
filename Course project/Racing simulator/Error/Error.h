#pragma once
#include <string>

namespace Error {
    class Error : std::exception {
    private:
        std::string x;
    public:
        std::string get_error();
        Error(std::string x);
    };
}
