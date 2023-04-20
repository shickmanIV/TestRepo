#include "Chess.hpp"

bool Chess::capture(Piece& attacker, Piece& defender)
{
	//Temp code for basic game where attack always works
	bool success = true;

	if (success) {
		board[attacker.getX()][attacker.getY()] = nullptr;
		attacker.setPos(defender.getX(), defender.getY());
		board[defender.getX()][defender.getY()] = &attacker;
	}
	else {
		board[attacker.getX()][attacker.getY()] = nullptr;
	}

	return success;
}

//Construct each piece (ugh)
Chess::Chess() : whiteRookL(0, 0, true), whiteRookR(7, 0, true), blackRookL(0, 7, false), blackRookR(7, 7, false),
whiteKnightL(1, 0, true), whiteKnightR(6, 0, true), blackKnightL(1, 7, false), blackKnightR(6, 7, false),
whiteBishopL(2, 0, true), whiteBishopR(5, 0, true), blackBishopL(2, 7, false), blackBishopR(5, 7, false),
whiteQueen(3, 0, true), whiteKing(4, 0, true), blackQueen(3, 7, false), blackKing(4, 7, false),
whiteP1(0, 1, true), whiteP2(1, 1, true), whiteP3(2, 1, true), whiteP4(3, 1, true),
whiteP5(4, 1, true), whiteP6(5, 1, true), whiteP7(6, 1, true), whiteP8(7, 1, true),
blackP1(0, 6, false), blackP2(1, 6, false), blackP3(2, 6, false), blackP4(3, 6, false),
blackP5(4, 6, false), blackP6(5, 6, false), blackP7(6, 6, false), blackP8(7, 6, false), board{ nullptr } {
	//Constructor places each piece on board (I have no idea how to do this in a less boring way)
	board[0][0] = &whiteRookL;
	board[7][0] = &whiteRookR;
	board[0][7] = &blackRookL;
	board[7][7] = &blackRookR;
	board[1][0] = &whiteKnightL;
	board[6][0] = &whiteKnightR;
	board[1][7] = &blackKnightL;
	board[6][7] = &blackKnightR;
	board[2][0] = &whiteBishopL;
	board[5][0] = &whiteBishopR;
	board[2][7] = &blackBishopL;
	board[5][7] = &blackBishopR;
	board[3][0] = &whiteQueen;
	board[4][0] = &whiteKing;
	board[3][7] = &blackQueen;
	board[4][7] = &blackKing;
	board[0][1] = &whiteP1;
	board[1][1] = &whiteP2;
	board[2][1] = &whiteP3;
	board[3][1] = &whiteP4;
	board[4][1] = &whiteP5;
	board[5][1] = &whiteP6;
	board[6][1] = &whiteP7;
	board[7][1] = &whiteP8;
	board[0][6] = &blackP1;
	board[1][6] = &blackP2;
	board[2][6] = &blackP3;
	board[3][6] = &blackP4;
	board[4][6] = &blackP5;
	board[5][6] = &blackP6;
	board[6][6] = &blackP7;
	board[7][6] = &blackP8;
}

void Chess::printBoard()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[j][i] != nullptr) {
				board[j][i]->print();
			}
			else cout << "-";
		}
		cout << endl;
	}
}

bool Chess::makeMove(int posX, int posY, int destX, int destY)
{
	const type_info& pawnType = typeid(Pawn);
	Piece* piece = board[posX][posY], * passantTest = nullptr;
	int testX = piece->getX(), testY = piece->getY();//Plus one so don't check self for collision
	bool success = false, collided = false;

	//Set up initial test position for collision testing
	if (testX != destX) {
		if (testX > destX) {
			testX--;
		}
		else testX++;
	}
	if (testY != destY) {
		if (testY > destY) {
			testY--;
		}
		else testY++;
	}

	if (piece->canMove(destX, destY)) {//If movement is correct
		if (piece->getCollisionMatters()) {
			while (testX != destX || testY != destY) {
				if (board[testX][testY] != nullptr) { collided = true; }//Make sure piece isn't already here
				if (testX != destX) {
					if (testX > destX) {
						testX--;
					}
					else testX++;
				}
				if (testY != destY) {
					if (testY > destY) {
						testY--;
					}
					else testY++;
				}
			}

		}
		if (piece->getCollisionMatters() && collided) {//If collision matters and there is collision
			success = false;
		}
		else {
			success = true;//Collision either doesn't matter, or there was no collision (either way there was success)
			if (board[destX][destY] != nullptr) {//If a piece is on the destination square
				if (board[destX][destY]->getIsWhite() != piece->getIsWhite()) {//If landing on opposing piece, can capture
					capture(*board[posX][posY], *board[destX][destY]);
				}
				else success = false;//else you're trying to capture your own piece
			}
			else if (typeid(*piece) == pawnType && posX != destX) {//Execute En Passant
				//Move attacking pawn
				board[destX][destY] = piece;
				board[posX][posY] = nullptr;
				piece->setPos(destX, destY);
				//Remove passanted pawn
				if (piece->getIsWhite()) {
					board[destX][destY - 1] = nullptr;
				}
				else {
					board[destX][destY + 1] = nullptr;
				}
			}else
			{//Taking an empty spot
				board[destX][destY] = piece;
				board[posX][posY] = nullptr;
				piece->setPos(destX, destY);
				
				if (typeid(*piece) == pawnType && abs(destY - posY) == 2) {//Set En Passant eligibility
					if (piece->getIsWhite()) {
						passantTest = board[destX - 1][destY];
						if (passantTest != nullptr && typeid(*passantTest) == pawnType) {
							dynamic_cast<Pawn*> (passantTest)->setRight(true);
						}
						passantTest = board[destX + 1][destY - 1];
						if (passantTest != nullptr && typeid(*passantTest) == pawnType) {
							dynamic_cast<Pawn*> (passantTest)->setLeft(true);
						}
					}
					else {
						destX = destX;
						destY = destY;
						passantTest = board[destX - 1][destY];
						if (passantTest != nullptr && typeid(*passantTest) == pawnType) {
							dynamic_cast<Pawn*> (passantTest)->setRight(true);
						}
						passantTest = board[destX + 1][destY];
						if (passantTest != nullptr && typeid(*passantTest) == pawnType) {
							dynamic_cast<Pawn*> (passantTest)->setLeft(true);
						}
					}
					
				}
			}
			
		}
	}

	return success;
}
