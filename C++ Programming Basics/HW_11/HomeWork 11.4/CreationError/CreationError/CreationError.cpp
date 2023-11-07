#include "CreationError.h"
#include <iostream>

namespace error {
	std::string Creation_error::get_error() {
		return ex;
	}

	Creation_error::Creation_error(std::string ex) : std::domain_error(ex) {
		this->ex = ex;
	}
}