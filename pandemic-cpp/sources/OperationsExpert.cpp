#include "OperationsExpert.hpp"
using namespace std;

namespace pandemic
{
    void OperationsExpert::build()
    {
        board.cities.at(cur_city).research_facility = true;
        board.stations.insert(cur_city);
    }
}
