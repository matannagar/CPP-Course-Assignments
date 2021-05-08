#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic
{

    Player &FieldDoctor::treat(City c)
    {
        if (cur_city == c)
        {
            Player::treat(c);
        }
        else
        {
            vector<City> &neighbors = board.cities.at(cur_city).neighbors; //list of my neighbors
            struct town &city = board.cities.at(c);                        // city struct which we want to cure
            //check if c is a neighbor of my city
            if (std::find(neighbors.begin(), neighbors.end(), c) != neighbors.end())
            {
                Player::inner_treat(c);
            }
            else
            {
                throw std::runtime_error("Treat FD: not a neighbor!");
            }
        }
        return *this;
    }
}
