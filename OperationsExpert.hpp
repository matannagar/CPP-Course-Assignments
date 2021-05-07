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
        virtual const string role() { return "OperationsExpert"; }
    };
}

#endif
