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
#include "SceneNode.h"

class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::Event ev;

	SceneNode* level;
	Player* player;
	background* Background;
	int levelCounter;

	//Resources

	//Player
	int* playerLives;

	//Private Functions
	void initWindow();
	void initBackground();
	void generateLevel(int _levelCounter);
	void initPlayer();

public:
	Game();
	virtual ~Game();

	//Functions
	void updatePollEvents();
	void updateLevel();
	void updatePlayer();
	void updateCollision();
	void update();
	void renderBG();
	void renderLevel();
	void renderPlayer();
	void render();
	const sf::RenderWindow& getWindow() const;
};

