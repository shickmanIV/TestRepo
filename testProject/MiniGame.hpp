#pragma once

#include <SFML/Graphics.hpp>
//#include "GraphicsChess.hpp" //CAUTION: May cause conflicts when both games are merged.
#include "MiniGameActor.hpp"

//Manages a bullet-hell minigame where the player must shoot down the enemy boss (the enemy piece)
//using their own piece as a character.
class MiniGame
{
public:
	//Create the window for the game to take place in.
	//TODO: Fix default parameters, currently produces empty square sprites.
	MiniGame(const sf::Texture& playerTexture = PieceTextures().whiteKing, 
			const sf::Color playerColor = sf::Color().White,
			const sf::Texture& enemyTexture = PieceTextures().blackKing,
			const sf::Color enemyColor = sf::Color().Black
	) :
		windowWidth(512),
		windowHeight(576),
		gameWindow(sf::VideoMode(512, 576), "MiniGame"),
		//background(sf::Vector2f(0.0f, 0.0f)),
		playerWins(false),
		player(playerTexture, sf::Vector2f(windowWidth / 2.0f, windowHeight * 3.0f / 4.0f)),
		enemy(enemyTexture, sf::Vector2f(windowWidth / 2.0f, windowHeight * 1.0f / 4.0f))
	{
		//Instantiate each sprite in boardSquares[][] for later use in drawing the chess board.
		createBackground();

		gameWindow.setFramerateLimit(60);
		spriteList.push_back(player);
		spriteList.push_back(enemy);
	}

	//Play the game, returning true if the player won, false otherwise.
	bool runRenderLoop();

private:
	sf::RenderWindow gameWindow;

	bool playerWins;

	MiniGameActor player;
	MiniGameActor enemy;
	
	int windowHeight;
	int windowWidth;

	std::vector<sf::Sprite> spriteList;

	//Taken from GraphicsTest. Used in rendering the chess board.
	sf::RectangleShape boardSquares[8][8];

	void processKeyPress(sf::Keyboard::Key& keyCode);

	void processKeyRelease(sf::Keyboard::Key& keyCode);

	//Not currently used
	void reportInputs(sf::Event event);

	//Instantiates each sprite in boardsquares[][]
	void createBackground();

	//Draws the chess board
	void drawBackground();

	
};