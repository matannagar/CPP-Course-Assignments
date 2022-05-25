#ifndef OPERATIONSEXPERT_H
#define OPERATIONSEXPERT_H

#include "Player.hpp"

namespace pandemic
{
    class OperationsExpert : public Player
    {
    public:
        using Player::Player;
        virtual void build();
        virtual string role() { return "OperationsExpert"; }
    };
}

#endif
