#include "Board.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace pandemic
{
    struct town TOWN;

    int Board::operator[](City i) const
    {
        return cities.at(i).level;
    }

    int &Board::operator[](City i)
    {
        sick_cities.push_back(i);
        return cities.at(i).level;
    }
    ostream &operator<<(ostream &os, const Board &board)
    {
        cout << "<< operator" << endl;
        return os;
    }
    bool Board::is_clean()
    {
        for (uint i = 0; i < sick_cities.size(); i++)
        {
            if (cities.at(sick_cities.at(i)).level > 0)
            {
                return false;
            }
        }
        return true;
    }
    void Board::remove_cures()
    {
        for (std::map<Color,bool>::iterator it=cures_found.begin(); it!=cures_found.end(); ++it){
            it->second=false;
        }
    }
}
