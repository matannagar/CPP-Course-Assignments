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
        else if (myCards.count(c) > 0 ) //check that i have the card and level>0
        {
            Player::inner_treat(c);
            myCards.erase(c);
        }
        else
        {
            throw("Treat func: city is already cured or i dont have right card!");
        }
        return *this;
    }
}
