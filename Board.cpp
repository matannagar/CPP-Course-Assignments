#include "Board.hpp" //import the interface
#include "Direction.hpp"

#include <iostream>    //input output stream , string
#include <cstring>
#include <array>
#include <vector>
#include <string>

using namespace std;

using ariel::Direction;

namespace ariel
{

  void extendRows(vector<vector<char>>& board, int rows){
    int curr_rows = board.size()-1;
    int curr_columns = board[0].size();

    vector<char> temp(curr_columns,'_');
    for(int i=curr_rows; i<rows-1;i++){
      board.emplace_back(temp);
    }
    
  }

  void extendColumns(vector<vector<char>>& board,int columns){

    int curr_rows = board.size()-1;
    int curr_columns = board[0].size()-1;

    for(int i=0; i<=curr_rows;i++){
      for (int j=curr_columns; j<columns-1;j++){
        board[i].push_back('_');
      }
    }
  } 
  void insertHorizontal(vector<vector<char>>& board,int row, int column,string message){
        string str_obj(message);
        char* char_arr;
        char_arr = &str_obj[0];

        int needed_cols= column+message.length()-1; // -1 because if i want col 5 its actually 4 

        if(column+message.length()>board[0].size()){
          extendColumns(board,needed_cols);
        }

        if(row>board.size()){
          extendRows(board,row);
        }
  
        for(int i=0;i<message.length();i++){
          board[row-1][column-1+i]=char_arr[i];
        }

  }
  
  void insertVertical(vector<vector<char>>& board,int row, int column,string message){
        string str_obj(message);
        char* char_arr;
        char_arr = &str_obj[0];

        int needed_rows= row+message.length()-1;

        if(row+message.length()>board.size()){
          extendRows(board,needed_rows);
        }

          // -1 because if i want col 5 its actually 4 

        if(column>board[0].size()){
          extendColumns(board,column);
        }

         for(int i=0;i<message.length();i++){
          board[row-1+i][column-1]=char_arr[i];
        }
  }
      
      void Board::post(unsigned int row, unsigned int column,Direction d, string message){
      if (message==""){
            throw invalid_argument("Illegal Input!");
            }

        int vec_rows = board.size();
        int vec_columns = board[0].size();

       

        if (Direction::Horizontal==d){
          insertHorizontal(board,row,column,message);
        
        }else{
        insertVertical(board,row,column,message);
         
        }
        cout<<"posted successfully!"<<endl;
      }
      

      std::string Board::read(unsigned int row, unsigned int column,Direction d, int message){
        int vec_rows = board.size();
        int vec_columns = board[0].size();
        string read;

        if (vec_rows < row+message){
          extendRows(board,row+message);
        }
        if (vec_columns < column+message){
          cout<<"extending now..."<<endl;
          extendColumns(board,column+message);
        }
        cout<<"made it here!"<<endl;
        if (Direction::Horizontal==d){
        for(int i=column;i<column+message;i++){
          read+=board[row-1][i-1];
        }
        
        }else{
        for(int i=row;i<row+message;i++){
          read+=board[i][column];
        }
        
        }

        return read;
      }

      void Board::show(){
        int vec_rows = board.size();
        int vec_columns = board[0].size();
        for(int i=0;i<vec_rows;i++){
          for(int j=0; j<vec_columns;j++){
            cout<<board[i][j];
          }
          cout<<endl;
        }
      }
  
}