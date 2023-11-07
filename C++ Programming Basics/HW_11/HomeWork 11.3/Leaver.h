#pragma once
#ifdef LeaverDinamicLib_EXPORTS
#define LEAVER_API __declspec(dllexport)
#else
#define LEAVER_API __declspec(dllimport)
#endif
#include <string>

namespace Leav {
	class Leaver {
	public:
		LEAVER_API std::string leave(std::string str);
		LEAVER_API Leaver();
	};
}

