#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;

namespace pandemic
{
    class Player
    {
    protected:
        City cur_city;
        virtual void inner_dis_cure(Color c, int req_cards);
        virtual void inner_treat(City c);

    public:
        Board &board;            // should not be here!!
        map<City, town> myCards; // for testing
        Player(Board &b, City ci) : board(b), cur_city(ci), myCards()
        {
        }
        void remove_cards()
        {
            myCards.clear();
        }
        City get_cur_city()
        {
            return cur_city;
        }
        virtual void build(); //builds research facility
        virtual void discover_cure(Color c);
        virtual string role(); //returns my role
        virtual Player &take_card(City card);
        virtual Player &drive(City city);
        virtual Player &fly_direct(City city);  // drop card of dest city
        virtual Player &fly_charter(City city); // drop card of src city
        virtual Player &fly_shuttle(City city); // if src has facility then it can reach dest with facility
        virtual Player &treat(City city);
    };
}

#endif
