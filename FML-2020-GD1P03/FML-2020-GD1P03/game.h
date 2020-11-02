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
//				: valeriia.blokhina@mds.ac.nz
//

#pragma once
#include "Player.h"
#include "background.h"

class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::Event ev;

	Player* player;
	background* Background;

	//Resources

	//Player

	//Private Functions
	void initWindow();
	void initBackground();
	void initPlayer();

public:
	Game();
	virtual ~Game();

	//Functions
	void updatePollEvents();
	void updatePlayer();
	void updateCollision();
	void update();
	void renderBG();
	void renderPlayer();
	void render();
	const sf::RenderWindow& getWindow() const;
};

