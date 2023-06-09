
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

		//Draw Background
		gameWindow.draw(background);

		
		//Draw Objects
		for (int i = 0; i < spriteList.size(); i++)
		{
			gameWindow.draw(spriteList[i]);
		}
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