#ifndef Board_H
#define Board_H

#include <iostream>
#include <string>
#include <vector>
#include "Direction.hpp"
using namespace std;
using ariel::Direction;

namespace ariel
{

  class Board
  {
    vector<vector<char>> board = {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}};
    ;
    // std::array<std::array<string,rows>,columns> board;

  public:
    Board(){};

    ~Board() {
      for (unsigned long i=0; i<board.size();i++){
        board.at(i).clear();
        board.at(i).shrink_to_fit();
      }
      board.clear();
      board.shrink_to_fit();
       cout << "Board destroyed" << endl; 
       }
    void post(unsigned int row, unsigned int column, Direction d, const string &message);
    std::string read(unsigned int row, unsigned int column, Direction d, unsigned int message);
    void show();
    void clear();
  };

}

#endif