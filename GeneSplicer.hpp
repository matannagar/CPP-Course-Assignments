#ifndef GENESPLICER_H
#define GENESPLICER_H

#include "Player.hpp"

namespace pandemic
{
class GeneSplicer : public Player
    {
        using Player::Player;
        public:
        virtual const string role(){return "Gene Splicer";}
        virtual void discover_cure(Color c); 
    };
}

#endif
