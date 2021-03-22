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
	board.post(/*row=*/4, /*column=*/5, Direction::Horizontal, "abcd");
	// board.post(/*row=*/8, /*column=*/5, Direction::Horizontal, "dcba");
	// board.post(/*row=*/1, /*column=*/1, Direction::Horizontal, "abcd");
	// board.post(/*row=*/3, /*column=*/5, Direction::Horizontal, "xtaf");
	// board.post(/*row=*/2, /*column=*/3, Direction::Horizontal, "abcd");
	// board.post(/*row=*/1, /*column=*/1, Direction::Vertical, "abcdefg");
	// board.post(/*row=*/7, /*column=*/7, Direction::Vertical, "abcdefg");
	// cout << board.read(/*row=*/99, /*column=*/201, Direction::Vertical, /*length=*/3) << endl;  
		// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).
	
	cout << board.read(/*row=*/4, /*column=*/5, Direction::Horizontal, /*length=*/10) << endl;  
		// prints "abyd__" (First letters are ab; then y from the "xyz"; then d; then two empty cells).

	board.show(); // shows the board in a reasonable way. For example:
		//    98:  _________
		//    99:  ____x____
		//    100: __abyd___
		//    101: ____z____
		//    102: _________
}

