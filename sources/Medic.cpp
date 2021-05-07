#include "Medic.hpp"
using namespace std;

namespace pandemic
{
    void Medic::clean_city()
    {
        struct town &city = board.cities.at(cur_city);
        if (board.cures_found.at(city.color))
        {
            city.level = 0;
        }

        board.medics.push_back(cur_city);
    }

    void Medic::update_lo()
    {
        vector<City> medics = board.medics;
        for (uint i = 0; i < medics.size(); i++)
        {
            if (medics.at(i) == cur_city)
            {
                medics.erase(medics.begin() + i);
                break;
            }
        }
    }

    Player &Medic::treat(City c)
    {
        struct town &city = board.cities.at(cur_city);
        if (city.level > 0)
        {
            city.level = 0;
        }
        else
        {
            throw runtime_error("Treat func: city is already cured!");
        }
        return *this;
    }

    Player &Medic::drive(City c)
    {
        update_lo();
        Player::drive(c);
        clean_city();
        return *this;
    }
    Player &Medic::fly_direct(City c)
    {
        update_lo();
        Player::fly_direct(c);
        clean_city();
        return *this;
    }
    Player &Medic::fly_charter(City c)
    {
        update_lo();
        Player::fly_charter(c);
        clean_city();
        return *this;
    }
    Player &Medic::fly_shuttle(City c)
    {
        update_lo();
        Player::fly_charter(c);
        clean_city();
        return *this;
    }
}
