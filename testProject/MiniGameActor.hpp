#pragma once

#include <SFML/Graphics.hpp>
#include "PieceTextures.hpp"
#include <iostream>

//An abstract class for defining the actions an object can take in the MiniGame.
class MiniGameActor : public sf::Sprite
{
public:
	MiniGameActor(const sf::Texture &actorTexture = PieceTextures().whiteKing, 
		const sf::Vector2f startPosition = sf::Vector2f(0, 0)) :
		velocity(0.0f, 0.0f),
		sf::Sprite(actorTexture)
	{
		this->setPosition(startPosition);
	}
	
	//Updates for each frame
	void update();

	void setMovingUp(const bool moveUp);
	void setMovingDown(const bool moveDown);
	void setMovingLeft(const bool moveLeft);
	void setMovingRight(const bool moveRight);

private:
	sf::Texture sourceTexture;
	sf::Vector2f velocity;
};