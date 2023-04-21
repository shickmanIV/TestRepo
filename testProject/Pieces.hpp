#pragma once

#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

class Piece {
protected:
	int posX;
	int posY;
	bool isWhite;//only two color options, so bool
	bool collisionMatters;

public:
	Piece(int newX, int newY, bool newIsWhite) {
		posX = newX;
		posY = newY;
		isWhite = newIsWhite;
		collisionMatters = true;
	}
	//Precondition: Move must be valid, this is not checked here
	void setPos(int newX, int newY);
	void setWhite(bool newIsWhite);

	//Getters
	int getX();
	int getY();
	bool getIsWhite();
	bool getCollisionMatters();

	//Test whether a piece could go from its pos to dest on a theoretically empty board (wrapper will check if the move actually works)
	virtual bool canMove(int destX, int destY) = 0;

	//Print the type of piece
	virtual void print() = 0;
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

	void setLeft(bool newTakeLeft);

	void setRight(bool newTakeRight);

	void print();
};

class Rook : public Piece {
public:
	Rook(int newX, int newY, bool newIsWhite) : Piece(newX, newY, newIsWhite) {};

	bool canMove(int destX, int destY);

	void print();
};

class Knight : public Piece {
public:
	Knight(int newX, int newY, bool newIsWhite) : Piece(newX, newY, newIsWhite) { collisionMatters = false; };

	bool canMove(int destX, int destY);

	void print();
};

class Bishop : public Piece {
public:
	Bishop(int newX, int newY, bool newIsWhite) : Piece(newX, newY, newIsWhite) {};

	bool canMove(int destX, int destY);

	void print();
};

class Queen : public Piece {
public:
	Queen(int newX = -1, int newY = -1, bool newIsWhite = false) : Piece(newX, newY, newIsWhite) {};//Default constructor for unassigned promotion queens

	bool canMove(int destX, int destY);

	void print();
};

class King : public Piece {
public:
	King(int newX, int newY, bool newIsWhite) : Piece(newX, newY, newIsWhite) {};

	bool canMove(int destX, int destY); //Castling involves multiple pieces and will be handled by the game, rather than the king itself

	void print();
};