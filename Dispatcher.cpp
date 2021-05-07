#include "Dispatcher.hpp"

using namespace std;

namespace pandemic
{
 Player& Dispatcher::fly_direct(City c)
    {
        if (board.cities.at(c).research_facility)
        {
            cout << "fly_direct_dispatcher: I'm going on a trip, dropping dest card" << endl;
            cur_city = c;
        }
        else
        {
            cout << "fly_direct_dispatcher: not in a fcility city!" << endl;
        }
        return *this;
    }
}
