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
    ostream &operator<<(ostream &os, const Board &board)
    {
        cout << "<< operator" << endl;
        return os;
    }
    bool Board::is_clean()
    {
        return false;
    }
}
