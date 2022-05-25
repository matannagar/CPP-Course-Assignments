#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>

#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic
{
    class town
    {
    public:
        Color color;
        vector<City> neighbors;
        bool research_facility;
        bool cure_found;
        int level;
    };

    class Board
    {
        map<City, int> board;

    public:
        Board()
        {
            cout << "Board" << endl;
        }
        map<City, town> cities;
        map<Color, bool> cures_found;
        vector<City> sick_cities;
        set<City> stations;
        vector<City> medics;
        int operator[](City i) const; // get operator
        int &operator[](City i);      // set operator
        bool is_clean();              // checks for disease
        void remove_cures();
        void remove_stations();
        friend ostream &operator<<(ostream &os, const Board &board);
    };
}
#endif
