#include "Player.hpp"
constexpr int five_cards = 5;
constexpr int zero_cards = 0;
using namespace std;

namespace pandemic
{
    void Player::build()
    {
    }
    void Player::discover_cure(Color c)
    {
    }
    void Player::inner_dis_cure(Color c, int req_cards)
    {
    }
    Player &Player::take_card(City card)
    {
        return (*this);
    }

    void Player::inner_treat(City c)
    {
    }
    Player &Player::treat(City c)
    {
        return *this;
    }
    Player &Player::drive(City c)
    {
        return *this;
    }
    Player &Player::fly_direct(City c)
    {
        return *this;
    }

    Player &Player::fly_charter(City c)
    {
        return *this;
    }

    Player &Player::fly_shuttle(City c)
    {
        return *this;
    }
    string Player::role()
    {
        return "general player";
    }
}
