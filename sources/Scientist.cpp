#include "Scientist.hpp"
constexpr int zero_cards = 0;
using namespace std;

namespace pandemic
{
    void Scientist::discover_cure(Color c)
    {
         cout<< "~~~~~~~~~~~~~~~~~~ helllllllllllllllo:" <<endl;
        if (board.cures_found.at(c))
        {
            return;
        }

        int count = 0;
        if (board.cities.at(cur_city).research_facility) //make sure city has facility
        {
            if (myCards.size() >= cards_req) // make sure there are enough cards
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
                cout<<"~~~~~~~~~~~~~~~~~~ num of cards:"<<count<<endl;
                if (count == cards_req) // remove them from my deck
                {
                    for (map<City, town>::iterator it = myCards.begin(); it != myCards.end(); it++)
                    {
                        if (it->second.color == c)
                        {
                            count--;
                            myCards.erase(it++);
                        }
                        if (count == zero_cards)
                        {
                            board.cures_found.at(c) = true;
                            cout<<"cure was found!!"<<endl;
                            break;
                        }
                    }
                }
                else
                {
                    throw runtime_error("Scientist:Could not find cure!");
                }
            }
            else
            {
                throw runtime_error("Scientist:Not enough cards!");
            }
        }
        else
        {
            throw runtime_error("Scientist:Not in a facility city!");
        }
    }
}
