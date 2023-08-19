#pragma once

//#include "GraphicsChess.hpp" //CAUTION: May cause conflicts when both games are merged.
#include "MiniGameActor.hpp"


//Used for reporting the current inputs
typedef enum inputs
{
	W, A, S, D, SPACE
} Inputs;

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
		playerWins(false),
		player(playerTexture, sf::Vector2f(206.0f, 400.0f)),//windowWidth / 2.0f, windowHeight * 3.0f / 4.0f)),
		enemy(enemyTexture, sf::Vector2f(206.0f, 100.0f))//windowWidth / 2.0f, windowHeight * 1.0f / 4.0f))
	{
		//Instantiate each sprite in boardSquares[][] for later use in drawing the chess board.
		createBackground();

		gameWindow.setFramerateLimit(60);
		
		entityList.push_back(&player);
		entityList.push_back(&enemy);
	}

	//Play the game, returning true if the player won, false otherwise.
	bool runRenderLoop();

private:
	EntityTracker entityTracker;

	bool playerWins;

	sf::RenderWindow gameWindow;

	int windowHeight;
	int windowWidth;
	
	MiniGameActor player;
	MiniGameActor enemy;

	std::vector<GameEntity*> entityList;

	bool inputList[5];

	//Taken from GraphicsTest. Used in rendering the chess board.
	sf::RectangleShape boardSquares[8][8];

	void processKeyPress(sf::Keyboard::Key& keyCode);

	void processKeyRelease(sf::Keyboard::Key& keyCode);

	//Not currently used
	void reportInputs();

	//Instantiates each sprite in boardsquares[][]
	void createBackground();

	//Draws the chess board
	void drawBackground();
};