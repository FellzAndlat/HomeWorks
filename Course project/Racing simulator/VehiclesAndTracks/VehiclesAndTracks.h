#pragma once
#include <string>
#ifdef VEHICLESANDTRACKS_EXPORTS
#define VEHICLESANDTRACKSLIB_API __declspec(dllexport)
#else
#define VEHICLESANDTRACKSLIB_API __declspec(dllimport)
#endif

namespace Vehicles {
    class Race_for_land_and_air_transport {
    protected:
        std::string name;
        double speed;
        int before_rest;
        double time;
    public:
        VEHICLESANDTRACKSLIB_API virtual double get_time();
        VEHICLESANDTRACKSLIB_API std::string get_name();
        VEHICLESANDTRACKSLIB_API Race_for_land_and_air_transport();
    };
    class Race_for_land_transport : public Race_for_land_and_air_transport {
    public:
        VEHICLESANDTRACKSLIB_API Race_for_land_transport();
    };
    class Centaur :public Race_for_land_transport {
    protected:
        double time_relax_static;
    public:
        VEHICLESANDTRACKSLIB_API double get_time();
        VEHICLESANDTRACKSLIB_API Centaur(double dist);
    };

    class Camel : public Centaur {
    protected:
        double time_relax1;
    public:
        VEHICLESANDTRACKSLIB_API double get_time();
        VEHICLESANDTRACKSLIB_API Camel(double dist);
    };

    class All_terrain_boots : public Camel {
    private:
        double time_relax1;
        double time_relax2;
    public:
        VEHICLESANDTRACKSLIB_API double get_time();
        VEHICLESANDTRACKSLIB_API All_terrain_boots(double dist);
    };

    class Camel_is_fast : public Camel {
    protected:
        double time_relax2;
    public:
        VEHICLESANDTRACKSLIB_API double get_time();
        VEHICLESANDTRACKSLIB_API Camel_is_fast(double dist);
    };

    class Race_for_air_transport : public Race_for_land_and_air_transport {
    public:
        VEHICLESANDTRACKSLIB_API Race_for_air_transport();
    };

    class Carpet_plane : public Race_for_air_transport {
    protected:
        double speed;
    public:
        VEHICLESANDTRACKSLIB_API double get_time();
        VEHICLESANDTRACKSLIB_API Carpet_plane(double dist);
    };

    class Broom : public Carpet_plane {
    public:
        VEHICLESANDTRACKSLIB_API double get_time();
        VEHICLESANDTRACKSLIB_API Broom(double dist);
    };

    class Eagle : public Broom {
    protected:
        double reduction;
    public:
        VEHICLESANDTRACKSLIB_API double get_time();
        VEHICLESANDTRACKSLIB_API Eagle(double dist);
    };
}