#include "Chess.hpp"
#include <iostream>

int main()
{
	Chess test;
	bool whiteWins = false;

	test.makeMove(3, 1, 3, 2);
	test.makeMove(2, 0, 6, 4);
	test.makeMove(4, 6, 4, 4);

	test.printBoard();

	cout << "Is game over? " << test.isWon(whiteWins) << endl;
	cout << "Did White Win? " << whiteWins << endl;

	

	return 0;
}