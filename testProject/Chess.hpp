#pragma once

#include "Pieces.hpp"

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
	Queen promote1, promote2, promote3, promote4, promote5, promote6, promote7, promote8;
	Piece* promotionStorage[8];
	bool whiteCastle, blackCastle;

	//THIS SHOULD IMPLEMENT MINIGAMES Returns true if capture was successful, if true, defender is removed, if false, attacker is
	bool capture(Piece& attacker, Piece& defender);

public:
	Chess();

	//Basic console print of board
	virtual void printBoard();

	/*If move is valid, it is made and true is returned, if invalid, board is unchanged and false is returned.
	passanted and castled aren't used by this class, but the graphics class uses them to update piece sprites*/
	bool makeMove(int posX, int posY, int destX, int destY, bool &passanted, bool &castled, bool isWhite);

	bool isWon(bool& whiteWins);

	//Gets move from console input for testing purposes
	void getMove(int& posX, int& posY, int& destX, int& destY, bool isWhite);

	virtual void game();
};