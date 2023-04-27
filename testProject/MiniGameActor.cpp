
#include "MiniGameActor.hpp"


void MiniGameActor::update()
{
	this->move(velocity * 1.0f);
}

void MiniGameActor::setMovingUp(const bool moveUp)
{
	if (moveUp)
	{
		velocity = sf::Vector2f(velocity.x, -1.0f);
	}
	else if (velocity.y == -1.0f)
	{
		velocity = sf::Vector2f(velocity.x, 0.0f);
	}
}

void MiniGameActor::setMovingDown(const bool moveDown)
{
	if (moveDown)
	{
		velocity = sf::Vector2f(velocity.x, 1.0f);
	}
	else if (velocity.y == 1.0f)
	{
		velocity = sf::Vector2f(velocity.x, 0.0f);
	}
}

void MiniGameActor::setMovingLeft(const bool moveLeft)
{
	if (moveLeft)
	{
		velocity = sf::Vector2f(-1.0f, velocity.y);
	}
	else if (velocity.x == -1.0f)
	{
		velocity = sf::Vector2f(0.0f, velocity.y);
	}
}

void MiniGameActor::setMovingRight(const bool moveRight)
{	
	if (moveRight)
	{
		velocity = sf::Vector2f(1.0f, velocity.y);
	}
	else if (velocity.x == 1.0f)
	{
		velocity = sf::Vector2f(0.0f, velocity.y);
	}
}

sf::Sprite* MiniGameActor::fireAt(MiniGameActor& targetActor)
{
	Projectile *p = new Projectile();

	return p;
}