#include "Leaver.h"

namespace Leav {
	std::string Leaver::leave(std::string str) {
		str = "До свидания, " + str + "!";
		return str;
	}
	Leaver::Leaver() {};
}