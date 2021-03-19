#include "Board.hpp" //import the interface
#include "Direction.hpp"

#include <iostream>    //input output stream , string
#include <cstring>
#include <array>
#include <string>

using namespace std;

using ariel::Direction;

namespace ariel
{
  void extendRows(vector<vector<char>>& board, int rows){
    int curr_rows = board.size()-1;
    int curr_columns = board[0].size()-1;
    vector<char> temp(curr_columns,'_');
    for(int i=curr_rows; i<rows;i++){
      board.emplace_back(temp);
    }
  }

  void extendColumns(vector<vector<char>>& board,int columns){
    int curr_rows = board.size()-1;
    int curr_columns = board[0].size()-1;
    for(int i=0; i<curr_rows;i++){
      for (int j=curr_columns; j<columns;j++){
        board[i].push_back('_');
      }
    }
  } 
  void insertHorizontal(vector<vector<char>>& board,int row, int column,string message){
        string str_obj(message);
        char* char_arr;
        char_arr = &str_obj[0];

        if(column+message.length()>board[0].size()){
          extendColumns(board,column+message.length());
        }

        for(int i=0;i<message.length()-1;i++){
          board[row-1][column-1+i]=char_arr[i];
        }

  }
  void insertVertical(vector<vector<char>>& board,int row, int column,string message){
        string str_obj(message);
        char* char_arr;
        char_arr = &str_obj[0];

        if(row+message.length()>board.size()){
          extendRows(board,row+message.length());
        }

         for(int i=0;i<message.length()-1;i++){
          board[row-1+i][column-1]=char_arr[i];
        }
  }
      Board::Board(int rows, int columns)
      { 
        this->columns= columns;
        this->rows= rows;
        
      };
      std::string Board::post(unsigned int row, unsigned int column,Direction d, const std::string message){
      if (row < 0 || column < 0 || message==""){
            throw invalid_argument("Illegal Input!");
            }
        int vec_rows = board.size();
        int vec_columns = board[0].size();

        if (Direction::Horizontal==d){
          insertHorizontal(board,row,column,message);
        }else{
        insertVertical(board,row,column,message);
        }
        return "Successfuly Posted!\n";
      };

      std::string Board::read(unsigned int row, unsigned int column,Direction d, int message){
        int vec_rows = board.size();
        int vec_columns = board[0].size();

        if (vec_rows < row){
          extendRows(board,row);
        }
        if (vec_columns < column){
          extendColumns(board,column);
        }
        if (Direction::Horizontal==d){
        for(int i=column;i<column+message;i++){
          cout<<board[row][i];
        }
        cout<<"\n";
        }else{
        for(int i=row;i<row+message;i++){
          cout<<board[i][column];
        }
        cout<<"\n";
        }

        return "reading\n";
      };

      void Board::show(){
        int vec_rows = board.size();
        int vec_columns = board[0].size();
        for(int i=0;i<vec_rows;i++){
          for(int j=0; j<vec_columns;j++){
            cout<<board[i][j];
          }
        }
      };
  
}