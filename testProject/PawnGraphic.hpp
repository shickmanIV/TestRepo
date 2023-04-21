#pragma once

#include <SFML/Graphics.hpp>
#include "PieceTextures.hpp"
#include "PieceGraphic.hpp"

class PawnGraphic : public PieceGraphic {
private:
	bool promoted;
	PieceTextures t;

public:
	PawnGraphic(bool newIsWhite) : PieceGraphic(newIsWhite) {
		promoted = false;
	};

	bool isPromoted();

	void promote();
};