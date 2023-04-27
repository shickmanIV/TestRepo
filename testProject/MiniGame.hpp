#pragma once

#include <SFML/Graphics.hpp>
//#include "GraphicsChess.hpp" //CAUTION: May cause conflicts when both games are merged.
#include "MiniGameActor.hpp"

//Manages a bullet-hell minigame where the player must shoot down the enemy boss (the enemy piece)
//using their own piece as a character.
class MiniGame
{
public:
	MiniGame(const sf::Texture& playerPiece, const sf::Color playerColor,
		const sf::Texture& enemyPiece, const sf::Color enemyColor) :
		windowWidth(512),
		windowHeight(576),
		gameWindow(sf::VideoMode(512, 576), "MiniGame"),
		background(sf::Vector2f(0.0f, 0.0f)),
		playerWins(false),
		player(playerPiece, sf::Vector2f(windowWidth / 2.0f, windowHeight * 3.0f / 4.0f)),
		enemy(enemyPiece, sf::Vector2f(windowWidth / 2.0f, windowHeight * 1.0f / 4.0f))
	{
		gameWindow.setFramerateLimit(60);
		background.setFillColor(sf::Color::Black);
		//spriteList.push_back(player);
		spriteList.push_back(enemy);
	}

	//Play the game, returning true if the player won, false otherwise.
	bool runRenderLoop();

private:
	sf::RenderWindow gameWindow;

	bool playerWins;

	sf::RectangleShape background;

	MiniGameActor player;
	MiniGameActor enemy;
	
	int windowHeight;
	int windowWidth;

	void processKeyPress(sf::Keyboard::Key& keyCode);

	void processKeyRelease(sf::Keyboard::Key& keyCode);

	void reportInputs(sf::Event event);

	std::vector<sf::Sprite> spriteList;
};