#include "GraphicsChess.hpp"

GraphicsChess::GraphicsChess() : screen(sf::VideoMode(512, 576), "Chess"), whiteP1(true), whiteP2(true), whiteP3(true), whiteP4(true),
whiteP5(true), whiteP6(true), whiteP7(true), whiteP8(true), blackP1(false), blackP2(false), blackP3(false), blackP4(false), blackP5(false),
blackP6(false), blackP7(false), blackP8(false), boardPieces{ nullptr }, whiteRookL(true), whiteRookR(true), whiteBishopL(true),
whiteBishopR(true), whiteKnightL(true), whiteKnightR(true), whiteQueen(true), whiteKing(true), blackRookL(false), blackRookR(false),
blackKnightL(false), blackKnightR(false), blackBishopL(false), blackBishopR(false), blackQueen(false), blackKing(false)
{

	sf::Color black(96, 116, 156);//This is objectively the best color for dark squares
	bool whiteStart = false, isWhite = false;
	//Board
	for (int i = 0; i < 8; i++) {
		whiteStart = i % 2;
		if (whiteStart) {
			isWhite = true;
		}
		else isWhite = false;
		for (int j = 0; j < 8; j++) {
			boardSquares[j][i].setSize(sf::Vector2f(64.f, 64.f));
			boardSquares[j][i].setPosition(sf::Vector2f(j * 64.f, i * 64.f));
			if (isWhite) {
				boardSquares[j][i].setFillColor(sf::Color::White);
			}
			else boardSquares[j][i].setFillColor(black);

			isWhite = !isWhite;
		}
	}

	//Piece Textures
	whiteRookL.setTexture(t.whiteRook, true);
	whiteRookR.setTexture(t.whiteRook, true);
	whiteKnightL.setTexture(t.whiteKnight, true);
	whiteKnightR.setTexture(t.whiteKnight, true);
	whiteBishopL.setTexture(t.whiteBishop, true);
	whiteBishopR.setTexture(t.whiteBishop, true);
	whiteQueen.setTexture(t.whiteQueen, true);
	whiteKing.setTexture(t.whiteKing, true);
	whiteP1.setTexture(t.whitePawn, true);
	whiteP2.setTexture(t.whitePawn, true);
	whiteP3.setTexture(t.whitePawn, true);
	whiteP4.setTexture(t.whitePawn, true);
	whiteP5.setTexture(t.whitePawn, true);
	whiteP6.setTexture(t.whitePawn, true);
	whiteP7.setTexture(t.whitePawn, true);
	whiteP8.setTexture(t.whitePawn, true);

	blackRookL.setTexture(t.blackRook, true);
	blackRookR.setTexture(t.blackRook, true);
	blackKnightL.setTexture(t.blackKnight, true);
	blackKnightR.setTexture(t.blackKnight, true);
	blackBishopL.setTexture(t.blackBishop, true);
	blackBishopR.setTexture(t.blackBishop, true);
	blackQueen.setTexture(t.blackQueen, true);
	blackKing.setTexture(t.blackKing, true);
	blackP1.setTexture(t.blackPawn, true);
	blackP2.setTexture(t.blackPawn, true);
	blackP3.setTexture(t.blackPawn, true);
	blackP4.setTexture(t.blackPawn, true);
	blackP5.setTexture(t.blackPawn, true);
	blackP6.setTexture(t.blackPawn, true);
	blackP7.setTexture(t.blackPawn, true);
	blackP8.setTexture(t.blackPawn, true);

	//Piece position
	whiteRookL.setPosition(sf::Vector2f(0.f, 0.f));
	whiteRookR.setPosition(sf::Vector2f(448.f, 0.f));
	whiteKnightL.setPosition(sf::Vector2f(64.f, 0.f));
	whiteKnightR.setPosition(sf::Vector2f(384.f, 0.f));
	whiteBishopL.setPosition(sf::Vector2f(128.f, 0.f));
	whiteBishopR.setPosition(sf::Vector2f(320.f, 0.f));
	whiteQueen.setPosition(sf::Vector2f(256.f, 0.f));
	whiteKing.setPosition(sf::Vector2f(192.f, 0.f));
	whiteP1.setPosition(sf::Vector2f(0.f, 64.f));
	whiteP2.setPosition(sf::Vector2f(64.f, 64.f));
	whiteP3.setPosition(sf::Vector2f(128.f, 64.f));
	whiteP4.setPosition(sf::Vector2f(192.f, 64.f));
	whiteP5.setPosition(sf::Vector2f(256.f, 64.f));
	whiteP6.setPosition(sf::Vector2f(320.f, 64.f));
	whiteP7.setPosition(sf::Vector2f(384.f, 64.f));
	whiteP8.setPosition(sf::Vector2f(448.f, 64.f));

	blackRookL.setPosition(sf::Vector2f(0.f, 448.f));
	blackRookR.setPosition(sf::Vector2f(448.f, 448.f));
	blackKnightL.setPosition(sf::Vector2f(64.f, 448.f));
	blackKnightR.setPosition(sf::Vector2f(384.f, 448.f));
	blackBishopL.setPosition(sf::Vector2f(128.f, 448.f));
	blackBishopR.setPosition(sf::Vector2f(320.f, 448.f));
	blackQueen.setPosition(sf::Vector2f(256.f, 448.f));
	blackKing.setPosition(sf::Vector2f(192.f, 448.f));
	blackP1.setPosition(sf::Vector2f(0.f, 384.f));
	blackP2.setPosition(sf::Vector2f(64.f, 384.f));
	blackP3.setPosition(sf::Vector2f(128.f, 384.f));
	blackP4.setPosition(sf::Vector2f(192.f, 384.f));
	blackP5.setPosition(sf::Vector2f(256.f, 384.f));
	blackP6.setPosition(sf::Vector2f(320.f, 384.f));
	blackP7.setPosition(sf::Vector2f(384.f, 384.f));
	blackP8.setPosition(sf::Vector2f(448.f, 384.f));

	//Store piece pointers
	boardPieces[0][0] = &whiteRookL;
	boardPieces[7][0] = &whiteRookR;
	boardPieces[0][7] = &blackRookL;
	boardPieces[7][7] = &blackRookR;
	boardPieces[1][0] = &whiteKnightL;
	boardPieces[6][0] = &whiteKnightR;
	boardPieces[1][7] = &blackKnightL;
	boardPieces[6][7] = &blackKnightR;
	boardPieces[2][0] = &whiteBishopL;
	boardPieces[5][0] = &whiteBishopR;
	boardPieces[2][7] = &blackBishopL;
	boardPieces[5][7] = &blackBishopR;
	boardPieces[4][0] = &whiteQueen;
	boardPieces[3][0] = &whiteKing;
	boardPieces[4][7] = &blackQueen;
	boardPieces[3][7] = &blackKing;
	boardPieces[0][1] = &whiteP1;
	boardPieces[1][1] = &whiteP2;
	boardPieces[2][1] = &whiteP3;
	boardPieces[3][1] = &whiteP4;
	boardPieces[4][1] = &whiteP5;
	boardPieces[5][1] = &whiteP6;
	boardPieces[6][1] = &whiteP7;
	boardPieces[7][1] = &whiteP8;
	boardPieces[0][6] = &blackP1;
	boardPieces[1][6] = &blackP2;
	boardPieces[2][6] = &blackP3;
	boardPieces[3][6] = &blackP4;
	boardPieces[4][6] = &blackP5;
	boardPieces[5][6] = &blackP6;
	boardPieces[6][6] = &blackP7;
	boardPieces[7][6] = &blackP8;
}

void GraphicsChess::printBoard()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			screen.draw(boardSquares[j][i]);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (boardPieces[j][i] != nullptr) {
				boardPieces[j][i]->setPosition(sf::Vector2f(64.f * j, 64.f * i));
				screen.draw(*boardPieces[j][i]);
			}
		}
	}
}

bool GraphicsChess::showMove(int posX, int posY, int destX, int destY, bool& passant, bool& castled, bool isWhite)
{
	const type_info& pawnType = typeid(PawnGraphic);
	sf::Sprite* temp = nullptr;

	if (boardPieces[posX][posY]->getWhite() == isWhite) {
		boardPieces[destX][destY] = boardPieces[posX][posY];
		boardPieces[posX][posY] = nullptr;
		if (passant) {
			if (isWhite) {
				boardPieces[destX][destY - 1] = nullptr;
			}
			else boardPieces[destX][destY + 1] = nullptr;
			passant = false;
		}
		else if (typeid(*boardPieces[destX][destY]) == pawnType) {//Promoting
			if ((isWhite && destY == 7) || (!isWhite && destY == 0)) {
				dynamic_cast<PawnGraphic*> (boardPieces[destX][destY])->promote();
			}
		}
		if (castled) {
			if (isWhite) {//If white castled
				if (destX == 1) {//short
					boardPieces[2][0] = boardPieces[0][0];
					boardPieces[0][0] = nullptr;
				}
				else {//long
					boardPieces[4][0] = boardPieces[7][0];
					boardPieces[7][0] = nullptr;
				}
			}
			else {//If black castled
				if (destX == 1) {//short
					boardPieces[2][7] = boardPieces[0][7];
					boardPieces[0][7] = nullptr;
				}
				else {//long
					boardPieces[4][7] = boardPieces[7][7];
					boardPieces[7][7] = nullptr;
				}
			}
			castled = false;
		}

		return true;
	}
	else return false;
}

void GraphicsChess::game()
{
	sf::Vector2i firstClick, secondClick;
	bool isFirstClick = true, hasClicked = false;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text text;
	sf::Text text2;
	text.setFont(font);
	text.setCharacterSize(32);
	text.setPosition(sf::Vector2f(0.f, 530.f));
	text.setFillColor(sf::Color::White);
	text2.setFont(font);
	text2.setCharacterSize(32);
	text2.setPosition(sf::Vector2f(0.f, 64.f));
	text2.setFillColor(sf::Color::White);

	bool whiteWins = false, whiteTurn = true, passanted = false, castled = false, firstTime = true;
	int posX = 0, posY = 0, destX = 0, destY = 0;

	while (screen.isOpen())
	{
		sf::Event event;
		if (firstTime) {
			text.setString("White to Move");
			screen.draw(text);
			printBoard();
			screen.display();
			firstTime = false;
		}
		while (screen.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				screen.close();

			if (event.type == sf::Event::MouseButtonReleased) {
				if (isFirstClick) {
					firstClick = sf::Mouse::getPosition(screen);
					posX = firstClick.x / 64;
					posY = firstClick.y / 64;

					isFirstClick = false;
				}
				else {
					secondClick = sf::Mouse::getPosition(screen);
					destX = secondClick.x / 64;
					destY = secondClick.y / 64;

					isFirstClick = true;
					hasClicked = true;
				}
			}
		}

		if (isWon(whiteWins)) {//Check for game over
			screen.clear();
			text.setPosition(sf::Vector2f(0.f, 0.f));
			text.setString("Game Over");
			screen.draw(text);
			if (whiteWins) {
				text2.setString("White Wins!");
			}
			else text2.setString("Black Wins!");
			screen.draw(text2);
			screen.display();
		}
		else if(hasClicked) {//If game isn't over
			if (whiteTurn) {
				screen.clear();
				if (makeMove(posX, posY, destX, destY, passanted, castled, true)) {
					showMove(posX, posY, destX, destY, passanted, castled, true);
					text.setString("Black to Move");
					whiteTurn = false;
				}
				else {
					text.setString("Invalid Move, white try again");
				}
				hasClicked = false;
				printBoard();
				screen.draw(text);
				screen.display();
				
			}
			else {
				screen.clear();
				if (makeMove(posX, posY, destX, destY, passanted, castled, false)) {
					showMove(posX, posY, destX, destY, passanted, castled, false);
					text.setString("White to Move");
					whiteTurn = true;
				}
				else {
					text.setString("Invalid Move, black try again");
				}
				hasClicked = false;
				printBoard();
				screen.draw(text);
				screen.display();
			}
		}

		
	}
}
