#ifndef DISPATCHER_H
#define DISPATCHER_H

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
class Dispatcher : public Player
    {
       using Player::Player;
    };
}

#endif
