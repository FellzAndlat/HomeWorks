#pragma once
#ifdef CREATIONERROR_EXPORTS
#define CREATIONERROR_API __declspec(dllexport)
#else
#define CREATIONERROR_API __declspec(dllimport)
#endif
#include <iostream>

namespace error {
    class Creation_error : public std::domain_error {
    private:
        std::string ex;
    public:
       CREATIONERROR_API std::string get_error();
       CREATIONERROR_API Creation_error(std::string ex);
    };
}