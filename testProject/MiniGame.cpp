
#include "MiniGame.hpp"


bool MiniGame::runRenderLoop()
{
	sf::Event event;

	while (gameWindow.isOpen())
	{
		//Process Events
		while (gameWindow.pollEvent(event))
		{
			//Request for closing the window
			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			}
			
			//Process key presses
			if (event.type == sf::Event::KeyPressed)
			{
				processKeyPress(event.key.code);
			}

			//Process key releases
			if (event.type == sf::Event::KeyReleased)
			{
				processKeyRelease(event.key.code);
			}

		}
		//Update actors
		player.update();
		enemy.update();

		//Clear previous frame
		gameWindow.clear();

		drawBackground();
		
		//Draw Objects -- BROKEN
		/*for (int i = 0; i < spriteList.size(); i++)
		{
			gameWindow.draw(spriteList[i]);
		}*/

		gameWindow.draw(player);
		gameWindow.draw(enemy);

		gameWindow.display();

	}
	return playerWins;
}

void MiniGame::processKeyPress(sf::Keyboard::Key& keyCode)
{
	//Test Messages
	std::cout << "Keys Detected: ";
	std::cout << (keyCode == sf::Keyboard::W ? "W" : " ");
	std::cout << (keyCode == sf::Keyboard::A ? " A" : "  ");
	std::cout << (keyCode == sf::Keyboard::S ? " S" : "  ");
	std::cout << (keyCode == sf::Keyboard::D ? " D" : "  ");
	std::cout << (keyCode == sf::Keyboard::Space ? " SPACE" : "      ");
	std::cout << std::endl;

	//Temp solution for determining who wins.
	if (keyCode == sf::Keyboard::I)
	{
		playerWins = true;
		gameWindow.close();
	}
	if (keyCode == sf::Keyboard::O)
	{
		playerWins = false;
		gameWindow.close();
	}



	if (keyCode == sf::Keyboard::W)
	{
		player.setMovingUp(true);
	}
	if (keyCode == sf::Keyboard::S)
	{
		player.setMovingDown(true);
	}
	if (keyCode == sf::Keyboard::A)
	{
		player.setMovingLeft(true);
	}
	if (keyCode == sf::Keyboard::D)
	{
		player.setMovingRight(true);
	}
	if (keyCode == sf::Keyboard::Space)
	{
		spriteList.push_back(*(player.fireAt(enemy)));
	}
}

void MiniGame::processKeyRelease(sf::Keyboard::Key& keyCode)
{
	if (keyCode == sf::Keyboard::W)
	{
		player.setMovingUp(false);
	}
	if (keyCode == sf::Keyboard::S)
	{
		player.setMovingDown(false);
	}
	if (keyCode == sf::Keyboard::A)
	{
		player.setMovingLeft(false);
	}
	if (keyCode == sf::Keyboard::D)
	{
		player.setMovingRight(false);
	}
}

void MiniGame::reportInputs(sf::Event event)
{

}

//Instantiates each sprite in boardsquares[][]
void MiniGame::createBackground()
{
	//Taken from GraphicsChess.
	sf::Color black(96, 116, 156);//This is objectively the best color for dark squares
	bool whiteStart = false, isWhite = false;
	
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
}

//Draws the chess board
void MiniGame::drawBackground()
{
	//taken from GraphicsChess::printBoard()
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			gameWindow.draw(boardSquares[j][i]);
		}
	}
}