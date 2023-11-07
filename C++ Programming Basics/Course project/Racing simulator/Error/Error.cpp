#include "Error.h"

namespace Error {
    std::string Error::get_error() {
        return x;
    }
    Error::Error(std::string x) {
        this->x = x;
    }
}