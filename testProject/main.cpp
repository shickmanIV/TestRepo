#include "Chess.hpp"
#include <iostream>

int main()
{
	Chess test;
	bool success = false;

	test.printBoard();

	test.makeMove(3, 1, 3, 2);
	test.makeMove(2, 0, 4, 2);
	test.makeMove(1, 0, 2, 2);

	test.printBoard();

	test.makeMove(3, 0, 2, 0);
	test.makeMove(2, 0, 3, 0);

	test.makeMove(3, 0, 1, 0);

	test.printBoard();

	return 0;
}