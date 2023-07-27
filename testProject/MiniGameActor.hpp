#pragma once

#include <SFML/Graphics.hpp>
#include "PieceTextures.hpp"
#include "Projectile.hpp"
#include <iostream>

//An abstract class for defining the actions an object can take in the MiniGame.
class MiniGameActor : public sf::Sprite
{
public:

	MiniGameActor(const sf::Texture& actorTexture = PieceTextures().whiteKing,
		const sf::Vector2f startPosition = sf::Vector2f(0, 0), const float actorSpeed = 2.0f) :
		sf::Sprite(actorTexture),
		speed(actorSpeed),
		isMovingUp(false),
		isMovingDown(false),
		isMovingLeft(false),
		isMovingRight(false)
	{
		this->setPosition(startPosition);
	}

	void updatePosition();

	void setMovingUp(const bool moveUp) { this->isMovingUp = moveUp; }
	void setMovingDown(const bool moveDown) { this->isMovingDown = moveDown; }
	void setMovingLeft(const bool moveLeft) { this->isMovingLeft = moveLeft; }
	void setMovingRight(const bool moveRight) { this->isMovingRight = moveRight; }

	//Returns the sprite of the projectile being created.
	//Sprite* fireAt(MiniGameActor& targetActor);

private:
	const sf::Texture sourceTexture; //unused

	const float speed;

	bool isMovingUp;
	bool isMovingDown;
	bool isMovingLeft;
	bool isMovingRight;
};