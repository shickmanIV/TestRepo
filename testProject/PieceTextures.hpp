#pragma once

//Images courtesy of John Pablock https://opengameart.org/content/chess-pieces-and-board-squares

#include <SFML/Graphics.hpp>

struct PieceTextures {
	sf::Texture whiteRook, whiteKnight, whiteBishop, whiteQueen, whiteKing, whitePawn;
	sf::Texture blackRook, blackKnight, blackBishop, blackQueen, blackKing, blackPawn;

	PieceTextures() {
		whiteRook.loadFromFile("w_rook.png");
		whiteKnight.loadFromFile("w_knight.png");
		whiteBishop.loadFromFile("w_bishop.png");
		whiteQueen.loadFromFile("w_queen.png");
		whiteKing.loadFromFile("w_king.png");
		whitePawn.loadFromFile("w_pawn.png");

		blackRook.loadFromFile("b_rook.png");
		blackKnight.loadFromFile("b_knight.png");
		blackBishop.loadFromFile("b_bishop.png");
		blackQueen.loadFromFile("b_queen.png");
		blackKing.loadFromFile("b_king.png");
		blackPawn.loadFromFile("b_pawn.png");

		
	}
};