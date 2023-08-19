
#include "GameEntity.hpp"

GameEntity::GameEntity(const sf::Texture& texture) : sf::Sprite(texture)
{
	entityTracker.push_back(this);
}