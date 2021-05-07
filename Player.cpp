#include "Player.hpp"
constexpr int five_cards = 5;
using namespace std;

namespace pandemic
{
    void Player::build()
    {
        if (myCards.count(cur_city) > 0)
        {
            board.cities.at(cur_city).research_facility = true;
        }
        else
        {
            throw("build function could not locate the city card!");
        }
    }
    void Player::discover_cure(Color c)
    {
        if (board.cures_found.at(c)){ return;}
        int count = 0;
        if (board.cities.at(cur_city).research_facility && myCards.size() >= five_cards) //make sure city has facility && enough cards in hand
        {
            for (map<City, town>::iterator it = myCards.begin(); it != myCards.end(); ++it) //count how many reds
            {
                if (it->second.color == c)
                {
                    count++;
                    if (count == five_cards)
                    {
                        break;
                    }
                }
            }
            if (count == five_cards) // remove them from my deck
            {
                for (map<City, town>::iterator it = myCards.begin(); it != myCards.end(); ++it)
                {
                    if (it->second.color == c)
                    {
                        myCards.erase(it++);
                    }
                    else
                    {
                        ++it;
                    }
                }
                board.cures_found.at(c) = true;
                cout << "Cure is found!" << endl;

                //loop through medics in dif cities, check if city is same color as new cure
                //if so, cure the city (cuz it has a docotor in it)
                for (uint i = 0; i < board.medics.size(); i++)
                {
                    if (board.cities.at(board.medics.at(i)).color == c)
                    {
                        board.cities.at(board.medics.at(i)).level = 0;
                    }
                }
            }
            else
            {
                throw std::runtime_error("find_cure: not enough colored cards!");
            }
        }
        else
        {
            throw std::runtime_error("find_cure: not enough cards || city does not have facility!");
        }
    }

    Player &Player::take_card(City card)
    {
        //assuming the system always work
        myCards.insert(pair<City, town>(card, board.cities.at(card)));
        cout << "card has just been inserted!" << endl;
        return (*this);
    }

    Player &Player::treat(City c)
    {
        if (c != cur_city)
        {
            throw std::runtime_error("TREAT: illegal action: you are not in correct city.");
        }
        struct town &city = board.cities.at(cur_city);
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
        cout << "city has just been treated!" << endl;
        return *this;
    }
    Player &Player::drive(City c)
    {
        struct town &city = board.cities.at(cur_city);

        std::vector<City>::iterator it;

        it = find(city.neighbors.begin(), city.neighbors.end(), c);
        if (it != city.neighbors.end())
        {
            cout << "Drive fun:I'm going on a trip" << endl;
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
        if (myCards.count(c) > 0)
        {
            cout << "fly_direct: I'm going on a trip, dropping dest card" << endl;
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
        if (myCards.count(cur_city) > 0)
        {
            cout << "fly_charter: I'm going on a trip, dropping src card" << endl;
            myCards.erase(cur_city);
            cur_city = c;
        }
        else
        {
            throw std::runtime_error("fly_charter:missing card!");
            // cout << "fly_charter: missing card!" << endl;
        }
        return *this;
    }
    Player &Player::fly_shuttle(City c)
    {
        map<City, town> &map = board.cities;
        if (map.at(cur_city).research_facility && map.at(c).research_facility)
        {
            cout << "fly_shuttle: Going on a trip!" << endl;
            cur_city = c;
        }
        else
        {
            throw std::runtime_error("fly_shuttle: one of the cities does not have a facility!");
            cout << "fly_shuttle: one of the cities does not have a facility!" << endl;
        }
        return *this;
    }
    const string Player::role()
    {
        return "general player";
    }
}
