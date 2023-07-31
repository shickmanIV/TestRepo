
#include "Projectile.hpp"
#include <iostream>

void Projectile::update()
{
	lifeTime++;

	//Update position
	this->move(DEFAULT_SPEED * direction);

	//TODO: Check for collision with target, pass event.

}