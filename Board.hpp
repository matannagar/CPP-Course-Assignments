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
        double operator[](City i) const { return board.at(i); }
        double &operator[](City i) { return board.at(i); }

        bool is_clean();

        friend ostream &operator<<(ostream &os, const Board &board);
    };

}

#endif
