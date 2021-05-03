#ifndef BOARD_H
#define BOARD_H

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <stdexcept>

#include <map>
#include "City.hpp"
using namespace std;

namespace pandemic
{

    class Board
    {
        map<City, double> board;

    public:
        double operator[](City i) const { return 0; }
        double &operator[](City i)
        {
            return board[i] = 2;
        }

        bool is_clean();
        void remove_cures();

        friend ostream &operator<<(ostream &os, const Board &board);
    };

}

#endif
