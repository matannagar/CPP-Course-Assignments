#ifndef FIELDDOCTOR_H
#define FIELDDOCTOR_H

#include "Player.hpp"

namespace pandemic
{
    class FieldDoctor : public Player
    {
    public:
        using Player::Player;

        virtual string role() { return "FieldDoctor"; };
        virtual Player &treat(City c);
    };
}

#endif
