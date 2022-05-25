#include "Dispatcher.hpp"

using namespace std;

namespace pandemic
{
 Player& Dispatcher::fly_direct(City c)
    {
        if (cur_city==c){ throw runtime_error("not allowd to fly from city to itself!");}
        if (board.cities.at(cur_city).research_facility)
        {
            cur_city = c;
        }
        else
        {
            Player::fly_direct(c);
        }
        return *this;
    }
}
