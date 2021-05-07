#include "Scientist.hpp"
constexpr int zero_cards = 0;
using namespace std;

namespace pandemic
{
    void Scientist::discover_cure(Color c)
    {
        if (board.cures_found.at(c)){ return;}
        int count = 0;
        if (board.cities.at(cur_city).research_facility) //make sure city has facility
        {
            for (map<City, town>::iterator it = myCards.begin(); it != myCards.end(); it++) //count how many reds
            {
                if (it->second.color == c)
                {
                    count++;
                    if (count == cards_req)
                    {
                        break;
                    }
                }
            }
            if (count == cards_req) // remove them from my deck
            {
                for (map<City, town>::iterator it = myCards.begin(); it != myCards.end(); it++)
                {
                    if (it->second.color == c)
                    {
                        myCards.erase(it++);
                        count--;
                    }
                    else
                    {
                        ++it;
                    }
                    if (count == zero_cards)
                    {
                        break;
                    }
                }
                cout << "Scientist: Cure was found!" << endl;
            }
        }
        else
        {
            throw runtime_error("Scientist:Could not find cure!");
        }
    }
}
