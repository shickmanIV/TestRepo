#include "Chess.hpp"
#include <iostream>

int main()
{
	Chess test;
	bool success = false;

	test.printBoard();

	test.makeMove(1, 1, 1, 3);
	test.makeMove(1, 3, 1, 4);

	test.makeMove(2, 6, 2, 4);
	test.printBoard();

	test.makeMove(1, 4, 2, 5);
	test.makeMove(2, 5, 2, 6);
	test.makeMove(2, 6, 1, 7);

	test.printBoard();

	return 0;
}