#ifndef VIROLOGIST_H
#define VIROLOGIST_H

#include "Player.hpp"

namespace pandemic
{
class Virologist : public Player
    {
        using Player::Player;
        public:
        virtual string role(){return "Virologist";}
        virtual Player& treat(City c);
    };
}

#endif
