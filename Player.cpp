#include "Player.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace pandemic
{
    void Player::build()
    {
    }
    void Player::discover_cure(Color c)
    {
    }

    Player Player::take_card(City a)
    {
        return *this;
    }

    string Player::role()
    {
        return "hi";
    }

    Player Player::treat(City c)
    {
        return *this;
    }
    Player Player::drive(City c)
    {
        return *this;
    }
    Player Player::fly_direct(City c)
    {
        return *this;
    }
    Player Player::fly_charter(City c)
    {
        return *this;
    }
    Player Player::fly_shuttle(City c)
    {
        return *this;
    }

    static bool check_cure_discovery(Player player);
}
