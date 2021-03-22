/**
 * Demo program for message-board exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */

#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	ariel::Board board;
	// board.post(/*row=+1*/10, /*column=*/10, Direction::Horizontal, "abcd");
	// cout <<board.read(/*row=*/10, /*column=*/10, Direction::Vertical, /*length=*/3) <<  endl;  
	// 	// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).
	// board.post(/*row=*/10, /*column=*/10, Direction::Vertical, "xyz");
	// cout << board.read(/*row=*/10, /*column=*/10, Direction::Horizontal, /*length=*/6) << endl;  
	// 	// prints "abyd__" (First letters are ab; then y from the "xyz"; then d; then two empty cells).

	// board.show(); // shows the board in a reasonable way. For example:
		//    98:  _________
		//    99:  ____x____
		//    100: __abyd___
		//    101: ____z____
		//    102: _________
board.post(0,0,Direction::Vertical,"abc");
board.post(0,1,Direction::Vertical,"def");
board.post(0,2,Direction::Vertical,"ghi");
board.show();
//read the entire board letter by letter
cout<<board.read(0,1,Direction::Vertical,1)<<endl;
}

