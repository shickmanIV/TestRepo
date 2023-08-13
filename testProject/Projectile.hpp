#pragma once

#include "GameEntity.hpp"

#define DEFAULT_SPEED 4.0f

//class Projectile : public GameEntity
//{
//public:
//	Projectile(sf::Vector2f direction) : direction(direction), lifeTime(0);
//
//	void update();
//
//private:
//	static const sf::Texture projectileTexture;
//
//	//A unit vector
//	const sf::Vector2f direction;
//
//	//The number of updates() run
//	int lifeTime;
//
//	//Pass an event to report a successful hit
//	void reportHit();
//};