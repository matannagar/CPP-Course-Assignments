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
            Player::inner_dis_cure(c, req_cards);
        }
        else
        {
            throw runtime_error("Scientist:Not in a facility city!");
        }
    }
}
