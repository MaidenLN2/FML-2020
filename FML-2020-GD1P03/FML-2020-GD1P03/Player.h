//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2020 Media Design School
//
// File Name	: player.h
// Description	: Header file for the player character
// Author		: Callum Boyce
//				: Lera Blokhina
// Mail			: callum.boyce@mds.ac.nz
//				: valeriia.blokhina@mds.ac.nz
//

#pragma once
#include "collision.h"

enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING};

class Player
{
private:
	sf::Texture textureSheet;
	sf::Sprite sprite;
	sf::Clock animationTimer;

	//Animation
	short animState;
	sf::IntRect currentFrame;
	bool animationSwitch;

	//Physics
	sf::Vector2f velocity;
	sf::Vector2f centerPos;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;
	bool jumping;

	//Core
	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();
	void initPhysics();

public:
	Player();
	virtual ~Player();

	//Accessors
	const bool& getAnimSwitch();
	const sf::Vector2f getPosition() const;
	sf::Vector2f getCenterPos();
	const sf::FloatRect getGlobalBounds() const;
	bool getJumping();
	sf::Sprite getSprite();
	float getVelocityX();
	float getVelocityY();
	float getVelocityMax();
	float getAcceleration();
	short getAnimState();

	//Modifiers
	void setCenterPos(sf::Vector2f updateCenterPos);
	void setPosition(const float x, const float y);
	void resetVelocityY();
	void setJumping(bool _jumping);
	void setVelocity(float x, float y);
	void setAnimState(short _state);

	//Functions
	void resetAnimationTimer();
	//void move(const float dir_x, const float dir_y, std::vector<std::vector<Tile*>> _tiles);
	void updatePhysics();
	//void updateMovement();
	void updateAnimations();
	void update();
	void render(sf::RenderTarget& target);

};
