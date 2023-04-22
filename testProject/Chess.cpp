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
whiteQueen(4, 0, true), whiteKing(3, 0, true), blackQueen(4, 7, false), blackKing(3, 7, false),
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
	board[4][0] = &whiteQueen;
	board[3][0] = &whiteKing;
	board[4][7] = &blackQueen;
	board[3][7] = &blackKing;
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
	promotionStorage[0] = &promote1;
	promotionStorage[1] = &promote2;
	promotionStorage[2] = &promote3;
	promotionStorage[3] = &promote4;
	promotionStorage[4] = &promote5;
	promotionStorage[5] = &promote6;
	promotionStorage[6] = &promote7;
	promotionStorage[7] = &promote8;
	whiteCastle = true;
	blackCastle = true;
}

void Chess::printBoard()
{
	cout << "  01234567" << endl;
	for (int i = 0; i < 8; i++) {
		cout << i << " ";
		for (int j = 0; j < 8; j++) {
			if (board[j][i] != nullptr) {
				board[j][i]->print();
			}
			else cout << "-";
		}
		cout << endl;
	}
}

bool Chess::makeMove(int posX, int posY, int destX, int destY, bool &passanted, bool &castled, bool isWhite)
{
	const type_info& pawnType = typeid(Pawn);
	const type_info& kingType = typeid(King);
	const type_info& rookType = typeid(Rook);
	Piece* piece = board[posX][posY], * pawnTest = nullptr;

	if (piece == nullptr) {//If somebody tries to move a piece that doesn't exist
		return false;
	}
	else if (piece->getIsWhite() != isWhite) {//Make sure person is moving their own piece
		return false;
	}

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
			else if (typeid(*piece) == pawnType && posX != destX) {//Pawn is moving to an empty square in capture form
				if (piece->getIsWhite() && board[destX][destY - 1] != nullptr && typeid(*(board[destX][destY - 1])) == pawnType) {//If is white pawn en passanting
					//Move attacking pawn
					board[destX][destY] = piece;
					board[posX][posY] = nullptr;
					piece->setPos(destX, destY);
					//Remove passanted pawn
					board[destX][destY - 1] = nullptr;
					passanted = true;
				}
				else if (!piece->getIsWhite() && board[destX][destY + 1] != nullptr && typeid(*(board[destX][destY + 1])) == pawnType) {//Black pawn is en passanting
					//Move attacking pawn
					board[destX][destY] = piece;
					board[posX][posY] = nullptr;
					piece->setPos(destX, destY);
					//Remove passanted pawn
					board[destX][destY + 1] = nullptr;
					passanted = true;
				}
				else {
					success = false;//Pawn was trying to capture a piece that moved already, shouldn't need to reset taking privelidge, attempt to capture should have done that
				}
			}else
			{//Taking an empty spot
				board[destX][destY] = piece;
				board[posX][posY] = nullptr;
				piece->setPos(destX, destY);
				
				if (typeid(*piece) == pawnType && abs(destY - posY) == 2) {//Set En Passant eligibility
					if (piece->getIsWhite()) {
						if (destX > 0) {//Don't check off board
							pawnTest = board[destX - 1][destY];
							if (pawnTest != nullptr && typeid(*pawnTest) == pawnType) {
								dynamic_cast<Pawn*> (pawnTest)->setRight(true);
							}
						}
						if (destX < 7) {
							pawnTest = board[destX + 1][destY];
							if (pawnTest != nullptr && typeid(*pawnTest) == pawnType) {
								dynamic_cast<Pawn*> (pawnTest)->setLeft(true);
							}
						}
					}
					else {
						if (destX > 0) {
							pawnTest = board[destX - 1][destY];
							if (pawnTest != nullptr && typeid(*pawnTest) == pawnType) {
								dynamic_cast<Pawn*> (pawnTest)->setRight(true);
							}
						}
						if (destX < 7) {
							pawnTest = board[destX + 1][destY];
							if (pawnTest != nullptr && typeid(*pawnTest) == pawnType) {
								dynamic_cast<Pawn*> (pawnTest)->setLeft(true);
							}
						}
					}
					
				}
			}
			
		}
	}
	else if(typeid(*piece) == kingType){//We'll check for castling here since it would be marked invalid by the king's canMove()
		if (piece->getIsWhite() && whiteCastle) {
			if (destX == 1 && destY == 0) {//White castle short
				if (board[1][0] == nullptr && board[2][0] == nullptr && board[0][0]->getIsWhite()) {//Make sure spaces are clear and rook is white
					success = true;
					castled = true;
					whiteCastle = false;
					board[1][0] = board[3][0];
					board[3][0] = nullptr;
					board[2][0] = board[0][0];
					board[0][0] = nullptr;
					board[1][0]->setPos(1, 0);
					board[2][0]->setPos(2, 0);
				}
			}
			else if (destX == 5 && destY == 0) {//White castle long
				if (board[4][0] == nullptr && board[5][0] == nullptr && board[6][0] == nullptr && board[7][0]->getIsWhite()) {
					success = true;
					castled = true;
					whiteCastle = false;
					board[5][0] = board[3][0];
					board[3][0] = nullptr;
					board[4][0] = board[0][0];
					board[7][0] = nullptr;
					board[5][0]->setPos(5, 0);
					board[4][0]->setPos(4, 0);
				}
			}
		}
		else if (!piece->getIsWhite() && blackCastle) {
			if (destX == 1 && destY == 7) {//Black castle short
				if (board[1][7] == nullptr && board[2][7] == nullptr && !board[0][7]->getIsWhite()) {//Make sure spaces are clear and rook is white
					success = true;
					castled = true;
					blackCastle = false;
					board[1][7] = board[3][7];
					board[3][7] = nullptr;
					board[2][7] = board[0][7];
					board[0][7] = nullptr;
					board[1][7]->setPos(1, 7);
					board[2][7]->setPos(2, 7);
				}
			}
			else if (destX == 5 && destY == 7) {//Black castle long
				if (board[4][7] == nullptr && board[5][7] == nullptr && board[6][7] == nullptr && !board[7][7]->getIsWhite()) {
					success = true;
					castled = true;
					blackCastle = false;
					board[5][7] = board[3][7];
					board[3][7] = nullptr;
					board[4][7] = board[0][7];
					board[7][7] = nullptr;
					board[5][7]->setPos(5, 7);
					board[4][7]->setPos(4, 7);
				}
			}
		}
	}
	if (success) {//Post Move updates
		if (typeid(*piece) == pawnType) {
			if (destY != 0 && destY != 7) {//Pawn not promoting
				if (piece->getIsWhite()) {//If a pawn moved, check if it opened up any attacks for itself
					if (destX > 0) {//Don't check off board
						if (board[destX - 1][destY + 1] != nullptr && !board[destX - 1][destY + 1]->getIsWhite()) {
							dynamic_cast<Pawn*> (piece)->setLeft(true);
						}
					}
					if (destX < 7) {
						if (board[destX + 1][destY + 1] != nullptr && !board[destX + 1][destY + 1]->getIsWhite()) {
							dynamic_cast<Pawn*> (piece)->setRight(true);
						}
					}
				}
				else {
					if (destX > 0) {
						if (board[destX - 1][destY - 1] != nullptr && board[destX - 1][destY - 1]->getIsWhite()) {
							dynamic_cast<Pawn*> (piece)->setLeft(true);
						}
					}
					if (destX < 7) {
						if (board[destX + 1][destY - 1] != nullptr && board[destX + 1][destY - 1]->getIsWhite()) {
							dynamic_cast<Pawn*> (piece)->setRight(true);
						}
					}
				}
			}
			else {//Pawn promoting
				for (int i = 0; i < 8; i++) {
					if (promotionStorage[i]->getX() == -1) {//If this promotion piece is unused
						board[destX][destY] = promotionStorage[i];
						promotionStorage[i]->setPos(destX, destY);
						if (piece->getIsWhite()) {//Don't need else since is false by default
							promotionStorage[i]->setWhite(true);
						}
						i = 2000;//End loop
					}
				}
			}
		}
		else if (typeid(*piece) == kingType || typeid(*piece) == rookType) {//Disable castling if rook or king moved
			if (piece->getIsWhite()) {
				whiteCastle = false;
			}
			else blackCastle = false;
		}

		if (piece->getIsWhite()) {//For any piece moves, check if piece has moved into a position where a pawn can take it
			if (destY != 7 && destY != 6) {//Probably don't need to worry about being captured by off-board pieces, and why would a pawn be behind its starting rank
				if (destX > 0) {//Don't check off board
					pawnTest = board[destX - 1][destY + 1];
					if (pawnTest != nullptr && typeid(*pawnTest) == pawnType && !pawnTest->getIsWhite()) {
						dynamic_cast<Pawn*> (pawnTest)->setRight(true);
					}
				}
				if (destX < 7) {
					pawnTest = board[destX + 1][destY + 1];
					if (pawnTest != nullptr && typeid(*pawnTest) == pawnType && !pawnTest->getIsWhite()) {
						dynamic_cast<Pawn*> (pawnTest)->setLeft(true);
					}
				}
			}
		}
		else {
			if (destY != 0 && destY != 1) {
				if (destX > 0) {
					pawnTest = board[destX - 1][destY - 1];
					if (pawnTest != nullptr && typeid(*pawnTest) == pawnType && pawnTest->getIsWhite()) {
						dynamic_cast<Pawn*> (pawnTest)->setRight(true);
					}
				}
				if (destX < 7) {
					pawnTest = board[destX + 1][destY - 1];
					if (pawnTest != nullptr && typeid(*pawnTest) == pawnType && pawnTest->getIsWhite()) {
						dynamic_cast<Pawn*> (pawnTest)->setLeft(true);
					}
				}
			}
		}
	}

	return success;
}

bool Chess::isWon(bool& whiteWins)
{
	bool blackLives = false, whiteLives = false;
	const type_info& kingType = typeid(King);

	for (int i = 0; i < 8; i++) {//Loop through board and check for both kings
		for (int j = 0; j < 8; j++) {
			if (board[j][i] != nullptr && typeid(*board[j][i]) == kingType) {
				if (board[j][i]->getIsWhite()) {
					whiteLives = true;
				}
				else blackLives = true;
			}
		}
	}
	if (!whiteLives) {
		whiteWins = false;
		return true;
	}
	else if(!blackLives) {
		whiteWins = true;
		return true;
	}

	return false;
}

void Chess::getMove(int& posX, int& posY, int& destX, int& destY, bool isWhite)
{
	do {
		cout << "Insert coordinates of piece to move (separate x and y coords by space): ";
		std::cin >> posX >> posY;
		if (board[posX][posY] != nullptr && board[posX][posY]->getIsWhite() == isWhite) {
			cout << "Insert coordinates to move to: ";
			std::cin >> destX >> destY;
		}
		else cout << "Have to move your own piece" << endl;
	} while (board[posX][posY] == nullptr || board[posX][posY]->getIsWhite() != isWhite);
	
}

void Chess::game()
{
	bool whiteWins = false, whiteTurn = true, passanted = false, castled = false;
	int posX = 0, posY = 0, destX = 0, destY = 0, count = 0;

	while (!isWon(whiteWins)) {
		if (whiteTurn) {
			printBoard();
			cout << "White's Move" << endl;
			count = 0;
			do {
				if (count > 0) {
					cout << "Invalid move, try again" << endl;
				}
				getMove(posX, posY, destX, destY, true);
			} while (!makeMove(posX, posY, destX, destY, passanted, castled, true));
			system("cls");
			whiteTurn = false;
		}
		else {
			printBoard();
			cout << "Black's Move" << endl;
			count = 0;
			do {
				if (count > 0) {
					cout << "Invalid move, try again" << endl;
				}
				getMove(posX, posY, destX, destY, false);
			} while (!makeMove(posX, posY, destX, destY, passanted, castled, false));
			system("cls");
			whiteTurn = true;
		}
		
	}
	cout << "Game complete! | ";
	if (whiteWins) {
		cout << "White Wins!" << endl;
	}
	else cout << "Black Wins!" << endl;
}
