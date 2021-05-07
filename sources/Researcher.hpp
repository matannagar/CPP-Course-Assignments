#ifndef RESEARCHER_H
#define RESEARCHER_H

#include "Player.hpp"

namespace pandemic
{
class Researcher : public Player
    {
        public:
        using Player::Player;
        virtual void discover_cure(Color c);
        virtual const string role(){return "Researcher";}
    };
}

#endif
