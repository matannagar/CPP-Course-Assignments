#include <iostream>
#include "doctest.h"   
#include <stdexcept>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

#include "OperationsExpert.hpp"

using namespace pandemic;

#include <string>
using namespace std; //used to include functions such as memcpy..

TEST_CASE("read_units")
{
	Board board;  // Initialize an empty board (with 0 disease cubes in any city).
	board[City::Kinshasa] = 3;      // put 3 yellow disease cubes in Kinshasa.
	board[City::Kinshasa] = 2;      // change number of disease cubes in Kinshasa to 2.
	board[City::MexicoCity] = 3;    // put 3 yellow disease cubes in MexicoCity
	board[City::HoChiMinhCity] = 1; // put 1 red disease cube in HoChiMinhCity
	board[City::Chicago] = 1; 
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);
CHECK_NOTHROW(board[City::Kinshasa] = 2);

}