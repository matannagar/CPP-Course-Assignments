#ifndef SCIENTIST_H
#define SCIENTIST_H

#include "Player.hpp"

namespace pandemic
{
    class Scientist : public Player
    {
        int req_cards;

    public:
        using Player::Player;
        Scientist(Board &b, City ci, int num)
            : Player{b, ci}, req_cards{num}
        {
        }

        virtual void discover_cure(Color c) override;
        virtual string role() override { return "Scientist"; }
    };
}

#endif
