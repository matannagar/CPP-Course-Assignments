#include "Researcher.hpp"
constexpr int five_cards = 5;
using namespace std;

namespace pandemic
{
    void Researcher::discover_cure(Color c)
    {
        if (board.cures_found.at(c)){ return;}
        int count = 0;

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
            cout << "Researcher: cure was found!" << endl;
        }
        else
        {
            throw runtime_error("Researcher:Could not find cure!");
        }
    }
}
