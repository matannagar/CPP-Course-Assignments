#ifndef RESEARCHER_H
#define RESEARCHER_H

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
class Researcher : public Player
    {
        public:
        Researcher(Board b, City ci);
    };
}

#endif
