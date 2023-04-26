#pragma once

#include <SFML/Graphics.hpp>

#define DEFAULT_SPEED 4.0f

class Projectile : public sf::Sprite
{
public:
	Projectile();

	void update();

private:
	//Points to the actor that fired the projectile.
	sf::Texture sourceTexture;

	//A unit vector
	sf::Vector2f direction;

	//The number of updates() run
	int lifeTime;
};