#include "Pieces.hpp"

void Piece::setPos(int newX, int newY)
{
	posX = newX;
	posY = newY;
}

void Piece::setWhite(bool newIsWhite)
{
	isWhite = newIsWhite;
}

int Piece::getX()
{
	return posX;
}

int Piece::getY()
{
	return posY;
}

bool Piece::getIsWhite()
{
	return isWhite;
}

bool Piece::getCollisionMatters()
{
	return collisionMatters;
}

bool Pawn::canMove(int destX, int destY)
{

	if (destX > 7 || destX < 0 || destY > 7 || destY < 0) {//Out of bounds check
		return false;
	}
	if (isWhite) {//For white
		if (destX == posX - 1 && destY == posY + 1) {//Check taking left
			if (canTakeLeft) {
				canTakeLeft = false;//Reset before letting them move so they don't do it again
				return true;
			}
			else return false;
		}
		if (destX == posX + 1 && destY == posY + 1) {//check taking right
			if (canTakeRight) {
				canTakeRight = false;
				return true;
			}
			else return false;
		}
		if (destX == posX) {//Not taking
			if (posY == 1 && destY == 3) {//Moving two as first move
				return true;
			}
			else if (destY == posY + 1) {//Moving one
				return true;
			}
			else return false;
		}
	}
	else {//For black
		if (destX == posX - 1 && destY == posY - 1) {//Check taking left
			if (canTakeLeft) {
				return true;
			}
			else return false;
		}
		if (destX == posX + 1 && destY == posY - 1) {//check taking right
			if (canTakeRight) {
				return true;
			}
			else return false;
		}
		if (destX == posX) {//Not taking
			if (posY == 6 && destY == 4) {//Moving two as first move
				return true;
			}
			else if (destY == posY - 1) {//Moving one
				return true;
			}
			else return false;
		}
	}
	return false;//This shouldn't ever be reached but just in case
}

void Pawn::setLeft(bool newTakeLeft)
{
	canTakeLeft = newTakeLeft;
}

void Pawn::setRight(bool newTakeRight)
{
	canTakeRight = newTakeRight;
}

void Pawn::setPassant(bool newPassant)
{
	getPassanted = newPassant;
}

bool Pawn::getPassant()
{
	return getPassanted;
}

void Pawn::print()
{
	cout << "p";
}

bool Rook::canMove(int destX, int destY)
{
	if (destX > 7 || destX < 0 || destY > 7 || destY < 0) {//Out of bounds check
		return false;
	}
	if (destX == posX || destY == posY) {//Rook needs one dimension to stay constant, other can be whatevers
		return true;
	}
	else return false;
}

void Rook::print()
{
	cout << "r";
}

bool Knight::canMove(int destX, int destY)
{
	if (destX > 7 || destX < 0 || destY > 7 || destY < 0) {//Out of bounds check
		return false;
	}
	if (destX == posX - 1 || destX == posX + 1) {// Right/Left one, Up/Down two
		if (destY == posY + 2 || destY == posY - 2) {
			return true;
		}
		else return false;
	}
	else if (destX == posX + 2 || destX == posX - 2) {// Up/Down two, Right/Left one
		if (destY == posY - 1 || destY == posY + 1) {
			return true;
		}
		else return false;
	}
	else return false;
	
}

void Knight::print()
{
	cout << "n";
}

bool Bishop::canMove(int destX, int destY)
{
	if (destX > 7 || destX < 0 || destY > 7 || destY < 0) {//Out of bounds check
		return false;
	}
	if (abs(destX - posX) == abs(destY - posY)) {//Make sure bishop is moving same amount right as left
		return true;
	}
	else return false;
}

void Bishop::print()
{
	cout << "b";
}

bool Queen::canMove(int destX, int destY)
{
	if (destX > 7 || destX < 0 || destY > 7 || destY < 0) {//Out of bounds check
		return false;
	}
	if (destX == posX || destY == posY) {//Moving like a rook
		return true;
	}
	else if (abs(destX - posX) == abs(destY - posY)) {//Moving like a bishop
		return true;
	}
	else return false;
}

void Queen::print()
{
	cout << "q";
}

bool King::canMove(int destX, int destY)
{
	if (destX > 7 || destX < 0 || destY > 7 || destY < 0) {//Out of bounds check
		return false;
	}
	if (abs(destX - posX) <= 1 && abs(destY - posY) <= 1) {//Make sure king is moving at most 1 horizontally and vertically
		return true;
	}
	else return false;
}

void King::print()
{
	cout << "k";
}
