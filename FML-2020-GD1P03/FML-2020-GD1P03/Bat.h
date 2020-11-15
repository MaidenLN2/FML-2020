#pragma once
#include "stdafx.h"

enum BAT_ANIMATION_STATES { BAT_LEFT = 0, BAT_RIGHT};

class Bat
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Clock animationTimer;
	sf::Vector2f startPos;
	float destX;

	//Animation
	short animState;
	sf::IntRect currentFrame;

	//Physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;

	//core
	void initTexture();
	void initSprite();
	void initAnimations();

public:
	Bat();
	Bat(float _startX, float _startY, float _destX);
	~Bat();

	//Accessors
	const sf::Vector2f getPosition() const;
	sf::Vector2f getCenterPos();
	const sf::FloatRect getGlobalBounds() const;
	sf::Sprite getSprite();
	float getVelocityX();
	float getStartX();
	float getDestX();

	//Modifiers
	void setVelocityX(float _velocity);

	//Functions
	void resetAnimationTimer();
	void updatePhysics();
	void updateAnimations();
	void updateMovement(float _start, float _dest);
	void update(float _start, float _dest);
	void render(sf::RenderTarget& target);
};

