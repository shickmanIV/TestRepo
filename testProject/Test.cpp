#include "Test.hpp"

void Test::testMove()
{
	Chess chess;
	bool passanted = false, castled = false;
	bool firstMove = false, secondMove = false;

	firstMove = chess.makeMove(3, 1, 3, 2, passanted, castled, true);
	secondMove = chess.makeMove(1, 0, 2, 2, passanted, castled, true);

	if (firstMove && secondMove) {
		cout << "Move Test PASSED" << endl;
	}
	else cout << "Move Test FAILED" << endl;
}

void Test::testCapture()
{
	Chess chess;
	bool passanted = false, castled = false;
	bool firstMove = false, secondMove = false;

	firstMove = chess.makeMove(3, 1, 3, 3, passanted, castled, true);
	chess.makeMove(4, 6, 4, 4, passanted, castled, false);
	secondMove = chess.makeMove(3, 3, 4, 4, passanted, castled, true);

	if (firstMove && secondMove) {
		cout << "Capture Test PASSED" << endl;
	}
	else cout << "Capture Test FAILED" << endl;
}

void Test::testEnPassant()
{
	Chess chess;
	bool passanted = false, castled = false;
	bool success = false;

	chess.makeMove(3, 1, 3, 3, passanted, castled, true);
	chess.makeMove(3, 3, 3, 4, passanted, castled, true);
	chess.makeMove(4, 6, 4, 4, passanted, castled, false);
	success = chess.makeMove(3, 4, 4, 5, passanted, castled, true);

	if (success && passanted) {
		cout << "En Passant Test PASSED" << endl;
	}
	else cout << "En Passant FAILED" << endl;
}

void Test::testCastle()
{
	Chess chess;
	bool passanted = false, castled = false;
	bool success = false;

	chess.makeMove(3, 1, 3, 2, passanted, castled, true);//Open up bishop
	chess.makeMove(1, 0, 2, 2, passanted, castled, true);//Move knight
	chess.makeMove(2, 0, 3, 1, passanted, castled, true);//Move bishop
	success = chess.makeMove(3, 0, 1, 0, passanted, castled, true);//Castle

	if (success && castled) {
		cout << "Castle Test PASSED" << endl;
	}
	else cout << "Castle Test FAILED" << endl;
}

void Test::testPromotion()
{
	Chess chess;
	bool passanted = false, castled = false;
	bool success = false;

	chess.makeMove(3, 1, 3, 3, passanted, castled, true);
	chess.makeMove(3, 3, 3, 4, passanted, castled, true);
	chess.makeMove(3, 4, 3, 5, passanted, castled, true);
	chess.makeMove(3, 5, 2, 6, passanted, castled, true);
	chess.makeMove(2, 6, 1, 7, passanted, castled, true);//Promotes
	success = chess.makeMove(1, 7, 5, 3, passanted, castled, true);//Make a move that a pawn can't do, but queen can

	if (success) {
		cout << "Promote Test PASSED" << endl;
	}
	else cout << "Promote Test FAILED" << endl;
}
