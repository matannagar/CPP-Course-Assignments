#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "Player.hpp"

namespace pandemic
{
    class Dispatcher : public Player
    {
    public:
        using Player::Player;

        virtual Player &fly_direct(City city); // drop card of dest city
        virtual string role() { return "Dispatcher"; }
    };
}

#endif
