#include "Leaver.h"

namespace Leav {
	std::string Leaver::leave(std::string str) {
		str = "�� ��������, " + str + "!";
		return str;
	}
	Leaver::Leaver() {};
}