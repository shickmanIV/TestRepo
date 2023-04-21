#pragma once

#include <SFML/Graphics.hpp>
#include "Chess.hpp"
#include "PieceTextures.hpp"
#include "PawnGraphic.hpp"

class GraphicsChess : public Chess {
private:
	sf::RenderWindow screen;
	sf::RectangleShape boardSquares[8][8];
	PieceGraphic* boardPieces[8][8];
	PieceGraphic whiteRookL, whiteRookR, blackRookL, blackRookR;
	PieceGraphic whiteKnightL, whiteKnightR, blackKnightL, blackKnightR;
	PieceGraphic whiteBishopL, whiteBishopR, blackBishopL, blackBishopR;
	PieceGraphic whiteQueen, blackQueen;
	PieceGraphic whiteKing, blackKing;
	PawnGraphic whiteP1, whiteP2, whiteP3, whiteP4, whiteP5, whiteP6, whiteP7, whiteP8,
		blackP1, blackP2, blackP3, blackP4, blackP5, blackP6, blackP7, blackP8;
	PieceTextures t;

public:
	GraphicsChess();

	void printBoard();

	//Updates the visual board based on the input move (precondition: the move has already been verified)
	bool showMove(int posX, int posY, int destX, int destY, bool& passant, bool& castled, bool isWhite);

	void game();
};