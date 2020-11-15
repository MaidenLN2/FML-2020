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
#include "collision.h"
#include "background.h"
#include "SceneNode.h"

#include <vector>

class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::Event ev;

	SceneNode* level;
	Player* player;
	background* Background;
	collision* collisionHandler;
	int levelCounter;

	//Resources

	//Player
	int* playerLives;

	//Private Functions
	void initWindow();
	void initBackground();
	void generateLevel(int _levelCounter);
	void checkLevelChange();
	void distanceDebug();
	void initPlayer();
	void initCollision();

public:
	Game();
	virtual ~Game();

	//Functions
	void updatePollEvents();
	void updateLevel();
	void updatePlayer();
	void updateCollision();
	void collisionChecker(std::vector<std::vector<Tile*>> _tiles);
	void update();
	void renderBG();
	void renderLevel();
	void renderPlayer();
	void render();
	const sf::RenderWindow& getWindow() const;
	void move(const float dir_x, const float dir_y/*, std::vector<std::vector<Tile*>> _tiles*/);
	void updatePlayerMovement();
	void updatePlayerCenterPos(Vector2f& playerCenterPos);

	//float SweptAABB(sf::Sprite b1, sf::Sprite b2, float& normalx, float& normaly);

	//void CollideWithMyAss(std::vector<std::vector<Tile*>> _tiles);
};

