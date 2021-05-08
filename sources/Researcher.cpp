#include "Researcher.hpp"
constexpr int five_cards = 5;
using namespace std;

namespace pandemic
{
    void Researcher::discover_cure(Color c)
    {

        if (board.cures_found.at(c))
        {
            return;
        } //if cure was found do nothing

        Player::inner_dis_cure(c, five_cards);
        //     int count = 0;

        //     for (map<City, town>::iterator it = myCards.begin(); it != myCards.end(); it++) //count how many reds
        //     {
        //         if (it->second.color == c)
        //         {
        //             count++;
        //         }
        //     }
        //     if (count >= five_cards) // found enough cards from same kind
        //     {
        //         count = five_cards;
        //         for (auto it = myCards.cbegin(); it != myCards.cend();) //iterate cards to remove them
        //         {
        //             if (it->second.color == c)
        //             {
        //                 count--;
        //                 myCards.erase(it++);
        //             }
        //             else
        //             {
        //                 ++it;
        //             }
        //             if (count == five_cards) //
        //             {
        //                 board.cures_found.at(c) = true;
        //                 return;
        //             }
        //         }
        //     }
        //     else
        //     {
        //         throw runtime_error("Researcher:Could not find cure!");
        //     }
        //     board.cures_found.at(c) = true;
    }
}
