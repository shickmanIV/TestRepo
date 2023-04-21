#include "GraphicsChess.hpp"

GraphicsChess::GraphicsChess() : screen(sf::VideoMode(512, 576), "Chess")
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
	whiteQueen.setPosition(sf::Vector2f(192.f, 0.f));
	whiteKing.setPosition(sf::Vector2f(256.f, 0.f));
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
	blackQueen.setPosition(sf::Vector2f(192.f, 448.f));
	blackKing.setPosition(sf::Vector2f(256.f, 448.f));
	blackP1.setPosition(sf::Vector2f(0.f, 384.f));
	blackP2.setPosition(sf::Vector2f(64.f, 384.f));
	blackP3.setPosition(sf::Vector2f(128.f, 384.f));
	blackP4.setPosition(sf::Vector2f(192.f, 384.f));
	blackP5.setPosition(sf::Vector2f(256.f, 384.f));
	blackP6.setPosition(sf::Vector2f(320.f, 384.f));
	blackP7.setPosition(sf::Vector2f(384.f, 384.f));
	blackP8.setPosition(sf::Vector2f(448.f, 384.f));
}

void GraphicsChess::printBoard()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			screen.draw(boardSquares[j][i]);
		}
	}
	screen.draw(whiteRookL);
	screen.draw(whiteRookR);
	screen.draw(whiteKnightL);
	screen.draw(whiteKnightR);
	screen.draw(whiteBishopL);
	screen.draw(whiteBishopR);
	screen.draw(whiteQueen);
	screen.draw(whiteKing);
	screen.draw(whiteP1);
	screen.draw(whiteP2);
	screen.draw(whiteP3);
	screen.draw(whiteP4);
	screen.draw(whiteP5);
	screen.draw(whiteP6);
	screen.draw(whiteP7);
	screen.draw(whiteP8);

	screen.draw(blackRookL);
	screen.draw(blackRookR);
	screen.draw(blackKnightL);
	screen.draw(blackKnightR);
	screen.draw(blackBishopL);
	screen.draw(blackBishopR);
	screen.draw(blackQueen);
	screen.draw(blackKing);
	screen.draw(blackP1);
	screen.draw(blackP2);
	screen.draw(blackP3);
	screen.draw(blackP4);
	screen.draw(blackP5);
	screen.draw(blackP6);
	screen.draw(blackP7);
	screen.draw(blackP8);
}

void GraphicsChess::game()
{
	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(32);
	text.setPosition(sf::Vector2f(0.f, 530.f));
	text.setFillColor(sf::Color::White);

	while (screen.isOpen())
	{
		sf::Event event;
		while (screen.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				screen.close();
		}

		screen.clear();
		bool whiteWins = false, whiteTurn = true, passanted = false;
		int posX = 0, posY = 0, destX = 0, destY = 0, count = 0;

		while (!isWon(whiteWins)) {
			if (whiteTurn) {
				printBoard();
				text.setString("White to Move");
				screen.draw(text);
				screen.display();
				count = 0;
				do {
					if (count > 0) {
						cout << "Invalid move, try again" << endl;
					}
					getMove(posX, posY, destX, destY, true);
				} while (!makeMove(posX, posY, destX, destY, passanted));
				system("cls");
				whiteTurn = false;
			}
			else {
				printBoard();
				text.setString("Black to Move");
				screen.draw(text);
				screen.display();
				count = 0;
				do {
					if (count > 0) {
						cout << "Invalid move, try again" << endl;
					}
					getMove(posX, posY, destX, destY, false);
				} while (!makeMove(posX, posY, destX, destY, passanted));
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
}
