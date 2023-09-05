#include "Creation_error.h"
#include <iostream>

Creation_error::Creation_error(std::string ex) : std::domain_error(ex) {
	std::cout << ex << '\n';
	std::cout << '\n';
}