#pragma once

#include <SFML/Graphics.hpp>
#include "MiniGameActor.hpp"

#define DEFAULT_SPEED 4.0f

class Projectile : public sf::Sprite
{
public:
	Projectile(sf::Vector2f direction) : direction(direction), lifeTime(0), sf::Sprite() {};

	void update();

private:
	//A unit vector
	const sf::Vector2f direction;

	//The number of updates() run
	int lifeTime;

	//Pass an event to report a successful hit
	void reportHit();
};