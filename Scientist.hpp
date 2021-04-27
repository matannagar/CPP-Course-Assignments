#ifndef SCIENTIST_H
#define SCIENTIST_H

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Player.hpp"

namespace pandemic
{
class Scientist : public Player
    {
        public:
        Scientist(Board b, City ci);
        Scientist(Board b, City ci, int num);
    };
}

#endif
