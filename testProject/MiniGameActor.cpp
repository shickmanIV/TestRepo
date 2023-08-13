#include "MiniGameActor.hpp"

//Handle the frame-by-frame movement of the actor
void MiniGameActor::update()
{
	sf::Vector2f actorVelocity(0.0f, 0.0f);

	if (isMovingUp && !isMovingDown)
	{
		actorVelocity.y = -1.0f;
	}
	else if (isMovingDown && !isMovingUp)
	{
		actorVelocity.y = 1.0f;
	}
	if (isMovingLeft && !isMovingRight)
	{
		actorVelocity.x = -1.0f;
	}
	else if (isMovingRight && !isMovingLeft)
	{
		actorVelocity.x = 1.0f;
	}

	this->move(speed * actorVelocity);
}

//sf::Sprite* MiniGameActor::fireAt(MiniGameActor& targetActor)
//{
//	Projectile *p = new Projectile();
//
//	return p;
//}