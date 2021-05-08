#include "Player.hpp"
constexpr int five_cards = 5;
constexpr int zero_cards = 0;
using namespace std;

namespace pandemic
{
    void Player::build()
    {
        if (board.stations.find(cur_city) == board.stations.end()) //check if station doesnt exist
        {
            if (myCards.count(cur_city) > 0)
            {
                board.cities.at(cur_city).research_facility = true;
                board.stations.insert(cur_city); // adds cur_city to list of facilitated cities
                myCards.erase(cur_city);         // drop card
            }
            else
            {
                throw("build function could not locate the city card!");
            }
        }
    }
    void Player::discover_cure(Color c)
    {
        if (board.cures_found.at(c))
        {
            return;
        }

        if (board.cities.at(cur_city).research_facility)
        {
            inner_dis_cure(c, five_cards);
        }
        else
        {
            throw std::runtime_error("city does not have facility!");
        }
    }
    void Player::inner_dis_cure(Color c, int req_cards)
    {
        int count = 0;

        if (myCards.size() >= req_cards) // make sure there are enough cards
        {
            for (map<City, town>::iterator it = myCards.begin(); it != myCards.end(); it++) //count how many reds
            {
                if (it->second.color == c)
                {
                    count++;
                }
            }
            if (count >= req_cards) // found enough cards from same kind
            {
                count = req_cards;
                for (auto it = myCards.cbegin(); it != myCards.cend();) //iterate cards to remove them
                {
                    if (it->second.color == c)
                    {
                        count--;
                        myCards.erase(it++);
                    }
                    else
                    {
                        ++it;
                    }
                    if (count == zero_cards) //
                    {
                        board.cures_found.at(c) = true;
                        return;
                    }
                }
            }
        }
        else
        {
            throw std::runtime_error("find_cure: not enough colored cards!");
        }
}
Player &Player::take_card(City card)
{
    //assuming the system always work
    myCards.insert(pair<City, town>(card, board.cities.at(card)));
    return (*this);
}

Player &Player::treat(City c)
{
    if (c != cur_city)
    {
        throw std::runtime_error("TREAT: illegal action: you are not in correct city.");
    }
    struct town &city = board.cities.at(c);
    if (city.level > 0)
    {
        if (board.cures_found.at(city.color)) //cure  found
        {
            city.level = 0;
        }
        else //cure not found
        {
            city.level--;
        }
    }
    else
    {
        throw std::runtime_error("Treat func: city is already cured!");
    }
    return *this;
}
Player &Player::drive(City c)
{
    if (cur_city == c)
    {
        throw std::runtime_error("Can't drive from city to itself!");
    };

    struct town &city = board.cities.at(cur_city);

    std::vector<City>::iterator it;

    it = find(city.neighbors.begin(), city.neighbors.end(), c);
    if (it != city.neighbors.end())
    {
        cur_city = c;
    }
    else
    {
        throw std::runtime_error("Drive:oops I am not a neighbor!");
        // cout << "Drive fun:oops I am not a neighbor!" << endl;
    };
    return *this;
}
Player &Player::fly_direct(City c)
{
    if (cur_city == c)
    {
        throw std::runtime_error("Can't fly from city to itself!");
    };

    if (myCards.count(c) > 0)
    {
        cur_city = c;
        myCards.erase(c);
    }
    else
    {
        throw std::runtime_error("fly_direct:missing card!");
        // cout << "fly_direct: missing card!" << endl;
    }
    return *this;
}

Player &Player::fly_charter(City c)
{
    if (cur_city == c)
    {
        throw std::runtime_error("Can't fly from city to itself!");
    };

    if (myCards.count(cur_city) > 0)
    {
        myCards.erase(cur_city);
        cur_city = c;
    }
    else
    {
        throw std::runtime_error("fly_charter:missing card!");
    }
    return *this;
}

Player &Player::fly_shuttle(City c)
{
    if (cur_city == c)
    {
        throw std::runtime_error("Can't fly from city to itself!");
    };
    map<City, town> &map = board.cities;
    if (map.at(cur_city).research_facility && map.at(c).research_facility)
    {
        cur_city = c;
    }
    else
    {
        throw std::runtime_error("fly_shuttle: one of the cities does not have a facility!");
    }
    return *this;
}
string Player::role()
{
    return "general player";
}
}
