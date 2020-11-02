//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2020 Media Design School
//
// File Name	: main.cpp
// Description	: Main file for creating the game class and running the loop
// Author		: Callum Boyce
//				: Lera Blokhina
// Mail			: callum.boyce@mds.ac.nz
//				: valeriia.blokhina@mds.ac.nz
//
#include "stdafx.h"
#include "Game.h"

int main()
{
	srand(static_cast<unsigned>(time(0)));

	Game game;

	while (game.getWindow().isOpen())
	{
		game.update();
		game.render();
	}

	//End Program
	return 0;
}