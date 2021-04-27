#ifndef VIROLOGIST_H
#define VIROLOGIST_H

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
class Virologist : public Player
    {
        using Player::Player;
    };
}

#endif
