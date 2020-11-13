//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2020 Media Design School
//
// File Name	: player.cpp
// Description	: Definition file for the player character
// Author		: Callum Boyce
//				: Lera Blokhina
// Mail			: callum.boyce@mds.ac.nz
//				: valeriia.blokhina@mds.ac.nz
//

#include "stdafx.h"
#include "Player.h"

void Player::initVariables()
{
	this->animState = JUMPING;
	this->setJumping(true);
}

void Player::initTexture()
{
	//Load texture from file
	if (!textureSheet.loadFromFile("Assets/Sprites/Squirrel Sprite Sheet.png", sf::IntRect(0, 0, 300, 400)))
	{
		std::cout << "ERROR::PLAYER::Assets/Sprites/Squirrel Sprite Sheet.png failed to load." << "\n";
	}
}

void Player::initSprite()
{
	//Set texture to sprite
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 32, 32);

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(2.5f, 2.5f);
}

void Player::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::initPhysics()
{
	this->velocityMax = 10.f;
	this->velocityMin = 0.3f;
	this->acceleration = 0.5f;
	this->drag = 0.9f;
	this->gravity = 1.01f;
	this->velocityMaxY = 30.f;
}

Player::Player()
{
	sf::Vector2f pos;
	pos.x = 50.f;
	pos.y = 50.f;
	this->sprite.setPosition(pos);
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
	this->initPhysics();
	this->centerPos.x = this->sprite.getGlobalBounds().left + (this->sprite.getGlobalBounds().width / 2);
	this->centerPos.y = this->sprite.getGlobalBounds().top + (this->sprite.getGlobalBounds().height / 2);
}

Player::~Player()
{
}

const bool& Player::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;
}

const sf::Vector2f Player::getPosition() const
{
	return this->sprite.getPosition();
}

const sf::Vector2f Player::getCenterPos() const
{
	return this->centerPos;
}

const sf::FloatRect Player::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

bool Player::getJumping()
{
	return this->jumping;
}

sf::Sprite Player::getSprite()
{
	return this->sprite;
}

float Player::getVelocityX()
{
	return this->velocity.x;
}

float Player::getVelocityY()
{
	return this->velocity.y;
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x,y);
}

void Player::resetVelocityY()
{
	this->velocity.y = 0.f;
}

void Player::setJumping(bool _jumping)
{
	this->jumping = _jumping;
}

void Player::setVelocity(float x, float y)
{
	this->velocity.x = x;
	this->velocity.y = y;
}

void Player::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::move(const float dir_x, const float dir_y)
{
	//Acceleration
	this->velocity.x += dir_x * this->acceleration;
	this->velocity.y += dir_y * this->acceleration;

	//Limit Velocity
	if (std::abs(velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
}

void Player::updatePhysics()
{
	//GRAVITY
	this->velocity.y += 1.0 * this->gravity;
	if (std::abs(velocity.y) > this->velocityMaxY)
	{
		this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}

	//Deceleration
	this->velocity *= this->drag;

	//Limit Deceleration
	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;

	this->sprite.move(this->velocity);
}

void Player::updateMovement()
{
	if(!this->getJumping())
		this->animState = IDLE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Move left
	{
		this->move(-1.f, 0.f);
		if(!this->getJumping())
		this->animState = MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Move Right
	{
		this->move(1.f, 0.f);
		if (!this->getJumping())
		this->animState = MOVING_RIGHT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && jumping == false) //Jump
	{
		this->move(0.f, -120.f);
		this->animState = JUMPING;
		this->setJumping(true);
	}
}

void Player::updateAnimations()
{
	if (this->animState == JUMPING)
	{
		if (this->velocity.y < -30.f)
		{
			this->currentFrame.top = 160;
			this->currentFrame.left = 64.f;

			this->sprite.setTextureRect(currentFrame);
		}

		else if (this->velocity.y >= -5.f)
		{
			this->currentFrame.top = 160;
			this->currentFrame.left = 96.f;

			this->sprite.setTextureRect(currentFrame);
		}
	}
	else if (this->animState == IDLE)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			this->currentFrame.top = 0;
			this->currentFrame.left += 32.f;
			if (this->currentFrame.left >= 192.f)
				this->currentFrame.left = 0.f;

			this->animationTimer.restart();
			this->sprite.setTextureRect(currentFrame);
		}
	}
	else if (this->animState == MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			this->currentFrame.top = 64;
			this->currentFrame.left += 32.f;
			if (this->currentFrame.left >= 256.f)
				this->currentFrame.left = 0.f;

			this->animationTimer.restart();
			this->sprite.setTextureRect(currentFrame);
		}
		this->sprite.setScale(2.5f, 2.5f);
		this->sprite.setOrigin(0.f, 0.f);
	}
	else if (this->animState == MOVING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			this->currentFrame.top = 64;
			this->currentFrame.left += 32.f;
			if (this->currentFrame.left >= 256.f)
				this->currentFrame.left = 0.f;

			this->animationTimer.restart();
			this->sprite.setTextureRect(currentFrame);
		}
		this->sprite.setScale(-2.5f, 2.5f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.5f, 0.f);
	}
	else
		this->animationTimer.restart();
}

void Player::update()
{
	this->updateMovement();
	this->updateAnimations();
	this->updatePhysics();
	this->centerPos.x = this->sprite.getGlobalBounds().left + (this->sprite.getGlobalBounds().width / 2);
	this->centerPos.y = this->sprite.getGlobalBounds().top + (this->sprite.getGlobalBounds().height / 2);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
