#include "Virologist.hpp"

using namespace std;

namespace pandemic
{
    Player &Virologist::treat(City c)
    {
        struct town &city = board.cities.at(c);

        if (cur_city == c)
        {
            Player::treat(c);
        }
        else if (myCards.count(c) > 0 && city.level > 0) //check that i have the card and level>0
        {
            if (city.cure_found) //cure  found
            {
                city.level = 0;
            }
            else //cure is found
            {
                city.level--;
                myCards.erase(c);
            }
        }
        else
        {
            throw("Treat func: city is already cured or i dont have right card!");
        }
        return *this;
    }
}
