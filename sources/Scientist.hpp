#ifndef SCIENTIST_H
#define SCIENTIST_H

#include "Player.hpp"

namespace pandemic
{
    class Scientist : public Player
    {
        int cards_req;

    public:
        using Player::Player;

        Scientist(Board& b, City ci, int num)
            : Player{b, ci},cards_req{num}
        {
        }

        virtual void discover_cure(Color c);
        virtual const string role(){return "Scientist";}
    };
}

#endif
