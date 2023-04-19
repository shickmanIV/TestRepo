#include "Chess.hpp"
#include <iostream>

int main()
{
	Chess test;
	bool success = false;

	test.printBoard();

	test.makeMove(1, 0, 2, 2);
	test.makeMove(2, 2, 3, 4);
	test.makeMove(3, 4, 4, 6);

	test.printBoard();

	return 0;
}