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
    }
}
