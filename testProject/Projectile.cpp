
#include "Projectile.hpp"
#include <iostream>

Projectile::Projectile() :
	direction(0.0f, -1.0f),
	lifeTime(0),
	sf::Sprite()
{
	//Creates a default texture
	sourceTexture.create(20, 20);
	this->setTexture(sourceTexture);
	this->setColor(sf::Color::Red);
	this->setPosition(0.0f, 0.0f);
}

void Projectile::update()
{
	this->move(DEFAULT_SPEED * direction);
}