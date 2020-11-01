//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2020 Media Design School
//
// File Name	: game.h
// Description	: Header file for the main loop
// Author		: Callum Boyce
//				: Lera Blokhina
// Mail			: callum.boyce@mds.ac.nz
//				:
//

#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>

class Game
{
private:
	//Window
	sf::RenderWindow* window;

	//Resources

	//Player

	//Private Functions
	void initWindow();

public:
	Game();
	virtual ~Game();

	//Functions
	void runGame();

	void updatePollEvents();
	void update();
	void render();
};

#endif // !__GAME_H__