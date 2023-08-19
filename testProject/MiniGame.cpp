
#include "MiniGame.hpp"


bool MiniGame::runRenderLoop()
{
	sf::Event event;

	while (gameWindow.isOpen())
	{
		//Process Events
		while (gameWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				gameWindow.close();
				break;
			case sf::Event::KeyPressed:
				processKeyPress(event.key.code);
				break;
			case sf::Event::KeyReleased:
				processKeyRelease(event.key.code);
				break;
			}
		}
		//reportInputs();

		//Clear previous frame
		gameWindow.clear();
		drawBackground();

		//Update and render all entities
		for (int i = 0; i < entityTracker.getSize(); i++)
		{
			entityTracker[i]->update();
			gameWindow.draw(*entityTracker[i]);
		}
		gameWindow.display();
	}
	return playerWins;
}

void MiniGame::processKeyPress(sf::Keyboard::Key& keyCode)
{
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

	//Movement Keys
	switch (keyCode)
	{
	case sf::Keyboard::W:
		player.setMovingUp(true);
		inputList[Inputs::W] = true;
		break;
	case sf::Keyboard::S:
		player.setMovingDown(true);
		inputList[Inputs::S] = true;
		break;
	case sf::Keyboard::A:
		player.setMovingLeft(true);
		inputList[Inputs::A] = true;
		break;
	case sf::Keyboard::D:
		player.setMovingRight(true);
		inputList[Inputs::D] = true;
		break;
	case sf::Keyboard::Space:
		//spriteList.push_back(*(player.fireAt(enemy)));
		inputList[Inputs::SPACE] = true;
		break;
	}
}

void MiniGame::processKeyRelease(sf::Keyboard::Key& keyCode)
{
	switch (keyCode)
	{
	case sf::Keyboard::W:
		player.setMovingUp(false);
		inputList[Inputs::W] = false;
		break;
	case sf::Keyboard::S:
		player.setMovingDown(false);
		inputList[Inputs::S] = false;
		break;
	case sf::Keyboard::A:
		player.setMovingLeft(false);
		inputList[Inputs::A] = false;
		break;
	case sf::Keyboard::D:
		player.setMovingRight(false);
		inputList[Inputs::D] = false;
		break;
	case sf::Keyboard::Space:
		inputList[Inputs::SPACE] = false;
		break;
	}
}

void MiniGame::reportInputs()
{
	std::cout << "Keys Detected: ";
	std::cout << (inputList[Inputs::W] ? "W" : " ");
	std::cout << (inputList[Inputs::A] ? " A" : "  ");
	std::cout << (inputList[Inputs::S] ? " S" : "  ");
	std::cout << (inputList[Inputs::D] ? " D" : "  ");
	std::cout << (inputList[Inputs::SPACE] ? " SPACE" : "      ");
	std::cout << std::endl;
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