#include <iostream>
#include "doctest.h" //include interface
#include "Board.hpp" //include interface
using namespace ariel; //ariel declared insdie snowman.hpp

#include <string>
using namespace std; //used to include functions such as memcpy...

//EMPTY BOARD 3x3 :
    //{'_', '_', '_'},
    //{'_', '_', '_'},
    //{'_', '_', '_'}

TEST_CASE("Horizontal Posting") {
ariel::Board board;
//fill the board 3x3
CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"a"));
CHECK_NOTHROW(board.post(0,1,Direction::Horizontal,"a"));
CHECK_NOTHROW(board.post(0,2,Direction::Horizontal,"a"));
CHECK_NOTHROW(board.post(1,0,Direction::Horizontal,"a"));
CHECK_NOTHROW(board.post(1,1,Direction::Horizontal,"a"));
CHECK_NOTHROW(board.post(1,2,Direction::Horizontal,"a"));
CHECK_NOTHROW(board.post(2,0,Direction::Horizontal,"a"));
CHECK_NOTHROW(board.post(2,1,Direction::Horizontal,"a"));
CHECK_NOTHROW(board.post(2,2,Direction::Horizontal,"a"));
//write over the board
CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"b"));
CHECK_NOTHROW(board.post(0,1,Direction::Horizontal,"b"));
CHECK_NOTHROW(board.post(0,2,Direction::Horizontal,"b"));
CHECK_NOTHROW(board.post(1,0,Direction::Horizontal,"b"));
CHECK_NOTHROW(board.post(1,1,Direction::Horizontal,"b"));
CHECK_NOTHROW(board.post(1,2,Direction::Horizontal,"b"));
CHECK_NOTHROW(board.post(2,0,Direction::Horizontal,"b"));
CHECK_NOTHROW(board.post(2,1,Direction::Horizontal,"b"));
CHECK_NOTHROW(board.post(2,2,Direction::Horizontal,"b"));
//write outside the board
CHECK_NOTHROW(board.post(3,3,Direction::Horizontal,"a"));
CHECK_NOTHROW(board.post(3,4,Direction::Horizontal,"a"));
CHECK_NOTHROW(board.post(3,5,Direction::Horizontal,"a"));
CHECK_NOTHROW(board.post(4,3,Direction::Horizontal,"a"));
CHECK_NOTHROW(board.post(4,4,Direction::Horizontal,"a"));
CHECK_NOTHROW(board.post(4,5,Direction::Horizontal,"a"));
CHECK_NOTHROW(board.post(5,3,Direction::Horizontal,"a"));
CHECK_NOTHROW(board.post(5,4,Direction::Horizontal,"a"));
CHECK_NOTHROW(board.post(5,5,Direction::Horizontal,"a"));
//fill the each line
CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"abc"));
CHECK_NOTHROW(board.post(0,1,Direction::Horizontal,"def"));
CHECK_NOTHROW(board.post(0,2,Direction::Horizontal,"ghi"));

CHECK_NOTHROW(board.post(0,0,Direction::Horizontal," ")); //check space
CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"")); //empty message 

board.clear();
}

TEST_CASE("Vertical Posting") {
    ariel::Board board;
//fill the board 3x3
CHECK_NOTHROW(board.post(0,0,Direction::Vertical,"a"));
CHECK_NOTHROW(board.post(0,1,Direction::Vertical,"a"));
CHECK_NOTHROW(board.post(0,2,Direction::Vertical,"a"));
CHECK_NOTHROW(board.post(1,0,Direction::Vertical,"a"));
CHECK_NOTHROW(board.post(1,1,Direction::Vertical,"a"));
CHECK_NOTHROW(board.post(1,2,Direction::Vertical,"a"));
CHECK_NOTHROW(board.post(2,0,Direction::Vertical,"a"));
CHECK_NOTHROW(board.post(2,1,Direction::Vertical,"a"));
CHECK_NOTHROW(board.post(2,2,Direction::Vertical,"a"));
//write over the board
CHECK_NOTHROW(board.post(0,0,Direction::Vertical,"b"));
CHECK_NOTHROW(board.post(0,1,Direction::Vertical,"b"));
CHECK_NOTHROW(board.post(0,2,Direction::Vertical,"b"));
CHECK_NOTHROW(board.post(1,0,Direction::Vertical,"b"));
CHECK_NOTHROW(board.post(1,1,Direction::Vertical,"b"));
CHECK_NOTHROW(board.post(1,2,Direction::Vertical,"b"));
CHECK_NOTHROW(board.post(2,0,Direction::Vertical,"b"));
CHECK_NOTHROW(board.post(2,1,Direction::Vertical,"b"));
CHECK_NOTHROW(board.post(2,2,Direction::Vertical,"b"));
//write outside the current limits
CHECK_NOTHROW(board.post(3,3,Direction::Vertical,"a"));
CHECK_NOTHROW(board.post(3,4,Direction::Vertical,"a"));
CHECK_NOTHROW(board.post(3,5,Direction::Vertical,"a"));
CHECK_NOTHROW(board.post(4,3,Direction::Vertical,"a"));
CHECK_NOTHROW(board.post(4,4,Direction::Vertical,"a"));
CHECK_NOTHROW(board.post(4,5,Direction::Vertical,"a"));
CHECK_NOTHROW(board.post(5,3,Direction::Vertical,"a"));
CHECK_NOTHROW(board.post(5,4,Direction::Vertical,"a"));
CHECK_NOTHROW(board.post(5,5,Direction::Vertical,"a"));
//fill the each line
CHECK_NOTHROW(board.post(0,0,Direction::Vertical,"abc"));
CHECK_NOTHROW(board.post(0,1,Direction::Vertical,"def"));
CHECK_NOTHROW(board.post(0,2,Direction::Vertical,"ghi"));

CHECK_NOTHROW(board.post(0,0,Direction::Vertical," ")); //check space
CHECK_NOTHROW(board.post(0,0,Direction::Vertical,"")); //empty message 

board.clear();
}


/*{'a', 'b', 'c'},
  {'d', 'e', 'f'},
  {'g', 'h', 'i'}*/
TEST_CASE("Horizontal Reading") {
ariel::Board board;
board.post(0,0,Direction::Horizontal,"abc");
board.post(1,0,Direction::Horizontal,"def");
board.post(2,0,Direction::Horizontal,"ghi");
//read the entire board letter by letter
CHECK(board.read(0,0,Direction::Horizontal,1)==string("a"));
CHECK(board.read(0,1,Direction::Horizontal,1)==string("b"));
CHECK(board.read(0,2,Direction::Horizontal,1)==string("c"));
CHECK(board.read(1,0,Direction::Horizontal,1)==string("d"));
CHECK(board.read(1,1,Direction::Horizontal,1)==string("e"));
CHECK(board.read(1,2,Direction::Horizontal,1)==string("f"));
CHECK(board.read(2,0,Direction::Horizontal,1)==string("g"));
CHECK(board.read(2,1,Direction::Horizontal,1)==string("h"));
CHECK(board.read(2,2,Direction::Horizontal,1)==string("i"));
//read the board line by line
CHECK(board.read(0,0,Direction::Horizontal,3)==string("abc"));
CHECK(board.read(1,0,Direction::Horizontal,3)==string("def"));
CHECK(board.read(2,0,Direction::Horizontal,3)==string("ghi"));
//read from the limits of the current board
CHECK(board.read(3,3,Direction::Horizontal,3)==string("___"));
CHECK(board.read(4,3,Direction::Horizontal,3)==string("___"));
CHECK(board.read(5,3,Direction::Horizontal,3)==string("___"));

}

TEST_CASE("Vertical Reading") {
ariel::Board board;
cout<<"lets begin!";
board.post(0,0,Direction::Vertical,"abc");
board.post(0,1,Direction::Vertical,"def");
board.post(0,2,Direction::Vertical,"ghi");
//read the entire board letter by letter
CHECK(board.read(0,0,Direction::Vertical,1)==string("a"));
CHECK(board.read(1,0,Direction::Vertical,1)==string("b"));
CHECK(board.read(2,0,Direction::Vertical,1)==string("c"));
CHECK(board.read(0,1,Direction::Vertical,1)==string("d"));
CHECK(board.read(1,1,Direction::Vertical,1)==string("e"));
CHECK(board.read(2,1,Direction::Vertical,1)==string("f"));
CHECK(board.read(0,2,Direction::Vertical,1)==string("g"));
CHECK(board.read(1,2,Direction::Vertical,1)==string("h"));
CHECK(board.read(2,2,Direction::Vertical,1)==string("i"));
//read the board line by line
CHECK(board.read(0,0,Direction::Vertical,3)==string("abc"));
CHECK(board.read(0,1,Direction::Vertical,3)==string("def"));
CHECK(board.read(0,2,Direction::Vertical,3)==string("ghi"));
//read from the limits of the current board
CHECK(board.read(3,3,Direction::Vertical,3)==string("___"));
CHECK(board.read(4,3,Direction::Vertical,3)==string("___"));
CHECK(board.read(5,3,Direction::Vertical,3)==string("___"));
}
