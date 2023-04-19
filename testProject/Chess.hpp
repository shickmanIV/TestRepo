#pragma once

#include "Pieces.hpp"
#include <memory>

class Chess {
private:
	Piece* board[8][8];
	Rook whiteRookL, whiteRookR, blackRookL, blackRookR;
	Knight whiteKnightL, whiteKnightR, blackKnightL, blackKnightR;
	Bishop whiteBishopL, whiteBishopR, blackBishopL, blackBishopR;
	Queen whiteQueen, blackQueen;
	King whiteKing, blackKing;
	Pawn whiteP1, whiteP2, whiteP3, whiteP4, whiteP5, whiteP6, whiteP7, whiteP8,
		blackP1, blackP2, blackP3, blackP4, blackP5, blackP6, blackP7, blackP8;

public:
	Chess();

	void printBoard();
};