#ifndef MEDIC_H
#define MEDIC_H

#include "Player.hpp"

namespace pandemic
{
class Medic : public Player
    {
        // using Player::Player;
        public:
        using Player::Player;
        void update_lo();
        void clean_city();
        
        virtual string role(){return "Medic";}
        virtual Player& treat(City c);
        virtual Player& drive(City city);
        virtual Player& fly_direct(City city); // drop card of dest city
        virtual Player& fly_charter(City city); // drop card of src city
        virtual Player& fly_shuttle(City city); // if src has facility then it can reach dest with facility
    };
}

#endif
