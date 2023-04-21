#pragma once

#include <SFML/Graphics.hpp>

class PieceGraphic : public sf::Sprite {
protected:
	bool isWhite;

public:
	PieceGraphic(bool newIsWhite) : sf::Sprite() {
		isWhite = newIsWhite;
	}

	virtual bool getWhite();
};