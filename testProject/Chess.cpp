#include "Chess.hpp"

//Construct each piece (ugh)
Chess::Chess() : whiteRookL(0, 0, true), whiteRookR(7, 0, true), blackRookL(0, 7, false), blackRookR(7, 7, false),
whiteKnightL(1, 0, true), whiteKnightR(6, 0, true), blackKnightL(1, 7, false), blackKnightR(6, 7, false),
whiteBishopL(2, 0, true), whiteBishopR(5, 0, true), blackBishopL(2, 7, false), blackBishopR(5, 7, false),
whiteQueen(3, 0, true), whiteKing(4, 0, true), blackQueen(3, 7, false), blackKing(4, 7, false),
whiteP1(0, 1, true), whiteP2(1, 1, true), whiteP3(2, 1, true), whiteP4(3, 1, true),
whiteP5(4, 1, true), whiteP6(5, 1, true), whiteP7(6, 1, true), whiteP8(7, 1, true),
blackP1(0, 6, false), blackP2(1, 6, false), blackP3(2, 6, false), blackP4(3, 6, false),
blackP5(4, 6, false), blackP6(5, 6, false), blackP7(6, 6, false), blackP8(7, 6, false) {
	//Constructor places each piece on board (I have no idea how to do this in a less boring way)
	board[0][0].reset(&whiteRookL);
	board[7][0].reset(&whiteRookR);
	board[0][7].reset(&blackRookL);
	board[7][7].reset(&blackRookR);
	board[1][0].reset(&whiteKnightL);
	board[6][0].reset(&whiteKnightR);
	board[1][7].reset(&blackKnightL);
	board[6][7].reset(&blackKnightR);
	board[2][0].reset(&whiteBishopL);
	board[5][0].reset(&whiteBishopR);
	board[2][7].reset(&blackBishopL);
	board[5][7].reset(&blackBishopR);
	board[3][0].reset(&whiteQueen);
	board[4][0].reset(&whiteKing);
	board[3][7].reset(&blackQueen);
	board[4][7].reset(&blackKing);
	board[0][1].reset(&whiteP1);
	board[1][1].reset(&whiteP2);
	board[2][1].reset(&whiteP3);
	board[3][1].reset(&whiteP4);
	board[4][1].reset(&whiteP5);
	board[5][1].reset(&whiteP6);
	board[6][1].reset(&whiteP7);
	board[7][1].reset(&whiteP8);
	board[0][6].reset(&blackP1);
	board[1][6].reset(&blackP2);
	board[2][6].reset(&blackP3);
	board[3][6].reset(&blackP4);
	board[4][6].reset(&blackP5);
	board[5][6].reset(&blackP6);
	board[6][6].reset(&blackP7);
	board[7][6].reset(&blackP8);
}
