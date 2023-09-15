#include "VehiclesAndTracks.h"

namespace Vehicles {
    double Race_for_land_and_air_transport::get_time() {
        return time;
    }
    std::string Race_for_land_and_air_transport::get_name() {
        return name;
    }
    Race_for_land_and_air_transport::Race_for_land_and_air_transport() {
        name = "Гонка для назменого и воздушного транспорта";
    }

    Race_for_land_transport::Race_for_land_transport() : Race_for_land_and_air_transport() {
        name = "Гонка для назменого транспорта";
    }

    double Centaur::get_time() {
        return time;
    }
    Centaur::Centaur(double dist) : Race_for_land_transport() {
        name = "Кентавр";
        speed = 15;
        before_rest = 8;
        time_relax_static = 2;

        time = dist / speed;
        time += (static_cast <int> (time) / before_rest) * time_relax_static;
    }

    double Camel::get_time() {
        return time;
    }
    Camel::Camel(double dist) : Centaur(dist) {
        name = "Верблюд";
        speed = 10;
        before_rest = 30;
        time_relax1 = 5;
        time_relax_static = 8;

        time = dist / speed;
        if (static_cast <int> (time) / before_rest > 1) {
            time += ((static_cast <int> (time) / before_rest) - 1) * time_relax_static;
            time += time_relax1;
        }
        else if (static_cast <int> (time) / before_rest == 1) {
            time += time_relax1;
        }
    }

    double All_terrain_boots::get_time() {
        return time;

    }
    All_terrain_boots::All_terrain_boots(double dist) : Camel(dist) {
        name = "Ботинки-вездеходы";
        speed = 6;
        before_rest = 60;
        time_relax1 = 10;
        time_relax_static = 5;

        time = dist / speed;
        if (static_cast <int> (time) / before_rest > 1) {
            time += ((static_cast <int> (time) / before_rest) - 1) * time_relax_static;
            time += time_relax1;
        }
        else if (static_cast <int> (time) / before_rest == 1) {
            time += time_relax1;
        }
    }

    double Camel_is_fast::get_time() {
        return time;
    }
    Camel_is_fast::Camel_is_fast(double dist) : Camel(dist) {
        name = "Верблюд-быстроход";
        speed = 40;
        before_rest = 10;
        time_relax1 = 5;
        time_relax2 = 6.5;
        time_relax_static = 8;

        time = dist / speed;
        if (static_cast<int> (time) / before_rest > 0) {
            time += time_relax1;
            if (static_cast<int> (time) / before_rest > 1) {
                time += time_relax2;
                if (static_cast<int> (time) / before_rest > 2) {
                    time += ((static_cast<int> (time) / before_rest) - 1) * time_relax_static;
                }
            }
        }

    }

    Race_for_air_transport::Race_for_air_transport() : Race_for_land_and_air_transport() {
        name = "Гонка для воздушного транспорта";
    }

    double Carpet_plane::get_time() {
        return time;
    }
    Carpet_plane::Carpet_plane(double dist) : Race_for_air_transport() {
        name = "Ковер-самолет";
        speed = 10;

        if (dist > 1000 && dist < 5000) {
            time = (dist * 0.97) / speed;
        }
        else if (dist > 5000 && dist < 10000) {
            time = (dist * 0.90) / speed;
        }
        else if (dist >= 10000) {
            time = (dist * 0.95) / speed;
        }
        else {
            time = dist / speed;
        }

    }

    double Broom::get_time() {
        return time;
    }
    Broom::Broom(double dist) : Carpet_plane(dist) {
        name = "Метла";
        speed = 20;

        time = (dist - (dist * ((dist / 1000) / 100))) / speed;
    }

    double Eagle::get_time() {
        return time;
    }
    Eagle::Eagle(double dist) : Broom(dist) {
        name = "Орел";
        speed = 8;

        time = (dist * 0.94) / speed;
    }
}