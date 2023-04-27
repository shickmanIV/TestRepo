#pragma once

#include "MiniGame.hpp"
#include "PieceTextures.hpp"

//A class for easy testing of the minigame
class MiniGameTest
{
public:
	//Retrieves the parameters needed to start a minigame.
	MiniGameTest()
	{
		PieceTextures pt;

		playerDefault = pt.whiteKing;
		enemyDefault = pt.blackKing;
	}

	void testOpenWindow()
	{
		MiniGame testGame(playerDefault, sf::Color::White, enemyDefault, sf::Color::Black);
		testGame.runRenderLoop();
	}

private:
	sf::Texture playerDefault;
	sf::Texture enemyDefault;
};