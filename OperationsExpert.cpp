#include "OperationsExpert.hpp"
using namespace std;

namespace pandemic
{
    void OperationsExpert::build()
    {
        board.cities.at(cur_city).research_facility = true;
        cout<<"OE: just built a research facility!"<<endl;
    }
}
