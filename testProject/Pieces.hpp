#pragma once

class Piece {
protected:
	int posX;
	int posY;
	bool isWhite;//only two color options, so bool

public:
	Piece(int newX, int newY, bool newIsWhite) {
		posX = newX;
		posY = newY;
		isWhite = newIsWhite;
	}
	//Precondition: Move must be valid, this is not checked here
	void setPos(int newX, int newY);

	//Test whether a piece could go from its pos to dest on a theoretically empty board (wrapper will check if the move actually works)
	virtual bool canMove(int destX, int destY) = 0;
};

class Pawn : public Piece {
private:
	bool canTakeLeft;
	bool canTakeRight;

public:
	Pawn(int newX, int newY, bool newIsWhite) : Piece(newX, newY, newIsWhite) {
		canTakeLeft = false;
		canTakeRight = false;
	};

	bool canMove(int destX, int destY);
};