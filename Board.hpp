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
     vector<vector<char>> board={
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };;
      // std::array<std::array<string,rows>,columns> board;

      public:
        Board(){
          // cout<<"i have been built"<<endl;
          // vector<vector<char>> board={{'_','_','_'},
          //                               {'_','_','_'},
          //                               {'_','_','_'}};
        };
        
        // ~Board(){cout<<"Board destroyed"<<endl;}
         void post(unsigned int a, unsigned int b,Direction d, const string &message);
         std::string read(unsigned int a, unsigned int b,Direction d, unsigned int message);
         void show();
         void clear();
  };
 
}

#endif