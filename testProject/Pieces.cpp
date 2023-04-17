#include "Pieces.hpp"

void Piece::setPos(int newX, int newY)
{
	posX = newX;
	posY = newY;
}

bool Pawn::canMove(int destX, int destY)
{

	if (destX > 7 || destX < 0 || destY > 7 || destY < 0) {//Out of bounds check
		return false;
	}
	if (isWhite) {//For white
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
			if (destY == 1 && posY == 3) {//Moving two as first move
				return true;
			}
			else if (destY == posY + 1) {//Moving one
				return true;
			}
			else return false;
		}
	}
	else {//For black
		if (destX == posX - 1 && destY == posY + 1) {//Check taking left
			if (canTakeLeft) {
				return true;
			}
			else return false;
		}
		if (destX == posX + 1 && destY == posY + 1) {//check taking right
			if (canTakeRight) {
				return true;
			}
			else return false;
		}
		if (destX == posX) {//Not taking
			if (destY == 6 && posY == 4) {//Moving two as first move
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

bool Rook::canMove(int destX, int destY)
{
	if (destX > 7 || destX < 0 || destY > 7 || destY < 0) {//Out of bounds check
		return false;
	}
	if (destX == posX || destY == posY) {//Rook needs one dimension to stay constant, other can be whatever
		return true;
	}
	else return false;
}
