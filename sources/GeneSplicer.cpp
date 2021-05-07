#include "GeneSplicer.hpp"

using namespace std;
constexpr int five_cards = 5;
constexpr int zero_cards = 0;
namespace pandemic
{
    void GeneSplicer::discover_cure(Color c)
    {
        if (board.cures_found.at(c))
        {
            return;
        }
        //make sure city has facility && at least 5 cards
        if (board.cities.at(cur_city).research_facility)
        {
            if (myCards.size() >= five_cards)
            {
                int count = five_cards;
                for (map<City, town>::iterator it = myCards.begin(); it != myCards.end(); ++it) //count how many cards
                {
                    if (count == zero_cards)
                    {
                        break;
                    }
                    myCards.erase(it++);
                    count--;
                }
                board.cures_found.at(c)=true;
            }
            else
            {
                throw runtime_error("GeneSplicer: not enough cards!");
            }
        }
        else
        {
            throw runtime_error("GeneSplicer: not in a research city!");
        }
    }
}
