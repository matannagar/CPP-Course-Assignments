#include "Scientist.hpp"
constexpr int zero_cards = 0;
using namespace std;

namespace pandemic
{
    void Scientist::discover_cure(Color c)
    {
        if (board.cures_found.at(c))
        {
            return;
        }

        int count = 0;
        if (board.cities.at(cur_city).research_facility) //make sure city has facility
        {
            Player::inner_dis_cure(c,req_cards);
        //     if (myCards.size() >= cards_req) // make sure there are enough cards
        //     {
        //         for (map<City, town>::iterator it = myCards.begin(); it != myCards.end(); it++) //count how many reds
        //         {
        //             if (it->second.color == c)
        //             {
        //                 count++;
        //             }
        //         }
        //         if (count >= cards_req) // found enough cards from same kind
        //         {
        //             count = cards_req;
        //             for (auto it = myCards.cbegin(); it != myCards.cend();) //iterate cards to remove them
        //             {
        //                 if (it->second.color == c)
        //                 {
        //                     count--;
        //                     myCards.erase(it++);
        //                 }
        //                 else
        //                 {
        //                     ++it;
        //                 }
        //                 if (count == zero_cards) //
        //                 {
        //                     board.cures_found.at(c) = true;
        //                     return;
        //                 }
        //             }
        //         }
        //         else
        //         {
        //             throw runtime_error("Scientist: could not find enough colored cards!");
        //         }
        //     }
        //     else
        //     {
        //         throw runtime_error("Scientist:Not enough cards!");
        //     }
        }
        else
        {
            throw runtime_error("Scientist:Not in a facility city!");
        }
    }
}
