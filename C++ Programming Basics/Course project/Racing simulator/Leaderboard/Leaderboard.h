#pragma once
#include <string>
#ifdef LEADERBOARD_EXPORTS
#define LEADERBOARDLIB_API __declspec(dllexport)
#else
#define LEADERBOARDLIB_API __declspec(dllimport)
#endif

namespace Leaderboard {
    class Leaderboard {
    private:
        std::string name;
        double time;
    public:
        LEADERBOARDLIB_API bool operator > (Leaderboard other);
        LEADERBOARDLIB_API Leaderboard& operator= (const Leaderboard& other);
        LEADERBOARDLIB_API std::string get_name();
        LEADERBOARDLIB_API double get_time();
        LEADERBOARDLIB_API Leaderboard(std::string name, double time);
    };
}
