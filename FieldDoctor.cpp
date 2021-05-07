#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic
{
    const string FieldDoctor::role(){return "Field Doctor";}
    Player& FieldDoctor::treat(City c)
    {
        vector<City> &neighbors = board.cities.at(cur_city).neighbors; //list of my neighbors
        struct town &city = board.cities.at(c);                        // city struct which we want to cure
        //check if c is a neighbor of my city
        if (std::find(neighbors.begin(), neighbors.end(), c) != neighbors.end())
        {
            if (city.level > 0)
            {
                if (city.cure_found) //cure  found
                {
                    city.level = 0;
                }
                else //cure not found
                {
                    city.level--;
                }
            }
            else
            {
                throw("Treat func: city is already cured!");
            }
        }
        return *this;
    }
}
