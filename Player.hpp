#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <stdexcept>

#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

using namespace std;

namespace pandemic
{
    class Player
    {
        City c;
        Board board;
        int x;

    public:
        Player(Board b, City ci)
        {
            board = b;
            c = ci;
        }

        Player(Board b, City ci, int num)
        {
            board = b;
            c = ci;
            x = num;
        }

        void build();
        void discover_cure(Color c);

        Player take_card(City a);

        string role();

        Player treat(City c);
        Player drive(City c);
        Player fly_direct(City c);
        Player fly_charter(City c);
        Player fly_shuttle(City c);

        static bool check_cure_discovery(Player player);
    };
}

#endif
