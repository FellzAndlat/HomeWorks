#include "Leaderboard.h"

namespace Leaderboard {
    bool Leaderboard::operator> (Leaderboard other) {
        return get_time() > other.get_time();
    }
    Leaderboard& Leaderboard::operator= (const Leaderboard& other) {
        name = other.name;
        time = other.time;
        return *this;
    }
    std::string Leaderboard::get_name() {
        return name;
    }
    double Leaderboard::get_time() {
        return time;
    }
    Leaderboard::Leaderboard(std::string name, double time) {
        this->name = name;
        this->time = time;
    }
}
