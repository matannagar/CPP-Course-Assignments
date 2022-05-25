#include "Board.hpp" //import the interface
#include "Direction.hpp"

#include <iostream> //input output stream , string
#include <cstring>
#include <array>
#include <vector>
#include <string>

using namespace std;

using ariel::Direction;

namespace ariel
{

  void extendRows(vector<vector<char>> &board, unsigned int rows)
  {
    board.size();

    // cout<<"extendRows!"<<endl;
    int curr_rows = board.size();

    unsigned int curr_columns = board.at(0).size();

    vector<char> temp(curr_columns, '_');
    for (unsigned int i = (unsigned int)curr_rows; i <= rows; i++)
    {
      board.emplace_back(temp);
    }
    //  cout<<"numbers of rows now are:" << board.size()<<endl;
  }

  void extendColumns(vector<vector<char>> &board, unsigned int columns)
  {

    unsigned int curr_rows = board.size() - 1;
    unsigned int curr_columns = board.at(0).size() - 1;

    for (unsigned int i = 0; i <= curr_rows; i++)
    {
      for (unsigned int j = curr_columns; j <= columns - 1; j++)
      {
        board.at(i).push_back('_');
      }
    }
    // cout<<"numbers of cols now are:" << board.at(0).size()<<endl;
  }
  void insertHorizontal(vector<vector<char>> &board, unsigned int row, unsigned int column, string message)
  {

    unsigned int needed_cols = column + message.length(); // -1 because if i want col 5 its actually 4

    if (column + message.length() >= board.at(0).size())
    {
      extendColumns(board, needed_cols);
    }

    if (row >= board.size())
    {
      extendRows(board, row);
    }

    for (unsigned int i = 0; i < message.length(); i++)
    {
      board.at(row).at(column + i) = message.at(i);
    }
  }

  void insertVertical(vector<vector<char>> &board, unsigned int row, unsigned int column, string message)
  {

    unsigned int needed_rows = row + message.length();
    // cout<<board.size()<<endl;

    if (row + message.length() >= board.size())
    {
      extendRows(board, needed_rows);
    }

    if (column >= board.at(0).size())
    {
      extendColumns(board, column);
    }

    for (unsigned int i = 0; i < message.length(); i++)
    {
      board.at(row + i).at(column) = message.at(i);
    }
  }

  void Board::post(unsigned int row, unsigned int column, Direction d, const string &message)
  {
    if (message.empty())
    {
      return;
    }

    if (Direction::Horizontal == d)
    {
      insertHorizontal(board, row, column, message);
    }
    else
    {
      insertVertical(board, row, column, message);
    }
  }

  std::string Board::read(unsigned int row, unsigned int column, Direction d, unsigned int message)
  {
    unsigned int vec_rows = board.size();
    unsigned int vec_columns = board.at(0).size();
    string read;

    if (vec_rows <= row + message)
    {

      extendRows(board, row + message);
    }
    if (vec_columns <= column + message)
    {

      extendColumns(board, column + message);
    }
    if (Direction::Horizontal == d)
    {
      for (unsigned int i = column; i < column + message; i++)
      {
        read += board.at(row).at(i);
      }
    }
    else
    {
      for (unsigned int i = row; i < row + message; i++)
      {
        read += board.at(i).at(column);
      }
    }
    return read;
  }

  void Board::show()
  {
    unsigned int vec_rows = board.size();
    unsigned int vec_columns = board.at(0).size();
    for (unsigned int i = 0; i < vec_rows; i++)
    {
      for (unsigned int j = 0; j < vec_columns; j++)
      {
        cout << board.at(i).at(j);
      }
      cout << endl;
    }
  }

  void Board::clear()
  {
    board = {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}};
  }

}