#ifndef Board_H
#define Board_H

#include <iostream>
#include <string>
#include <vector>
#include "Direction.hpp"
using namespace std;
using ariel::Direction;

namespace ariel{

  class Board
  {
      private:
      static int columns;
      static int rows;
      static vector<vector<char>> board;
      // std::array<std::array<string,rows>,columns> board;


      public:
        Board(){columns = 1; rows=1;};
        Board(int columns, int rows);
      static std::string post(unsigned int a, unsigned int b,Direction d, const std::string message);
      static std::string read(unsigned int a, unsigned int b,Direction d, int message);
      static void show();
  };
 
}

#endif