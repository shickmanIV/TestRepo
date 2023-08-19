#pragma once
#include <SFML/Graphics.hpp>
#include "EntityTracker.hpp"

//An abstract class used to streamline the frame-by-frame updates and destruction of moving objects.
//In this implementation, all game entities have a set sprite.
class GameEntity : public sf::Sprite
{
public:
	//GameEntity(const sf::Texture& texture, const sf::Vector2f startPosition = sf::Vector2f(0, 0)) :
	//	sf::Sprite(texture)
	GameEntity(const sf::Texture& texture);
	
	//Process frame-by-frame changes
	virtual void update() = 0;

private:
	static EntityTracker entityTracker;
};