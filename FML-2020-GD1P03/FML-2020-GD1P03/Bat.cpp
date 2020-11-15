#include "stdafx.h"
#include "Bat.h"

void Bat::initTexture()
{
	//Load texture from file
	if (!this->texture.loadFromFile("Assets/Sprites/Bat_Sprite_Sheet.png", sf::IntRect(0, 0, 80, 16)))
	{
		std::cout << "ERROR::BAT::Assets/Sprites/Bat_Sprite_Sheet.png failed to load." << "\n";
	}	
}

void Bat::initSprite()
{
	//Set texture to sprite
	this->sprite.setTexture(this->texture);
	this->currentFrame = sf::IntRect(0, 0, 16, 16);
	this->animState = BAT_RIGHT;
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(2.5f, 2.5f);
}

void Bat::initAnimations()
{
	this->animationTimer.restart();
}

//Constructor / Destructor
Bat::Bat()
{
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

Bat::Bat(float _startX, float _startY, float _destX)
{
	if (_destX > 0)
		this->animState = BAT_RIGHT;
	else
		this->animState = BAT_LEFT;
	this->initTexture();
	this->initSprite();
	this->initAnimations();
	this->startPos.x = _startX;
	this->startPos.y = _startY;
	this->sprite.setPosition(this->startPos);
	this->destX = _destX;
	this->velocity.x = 0.f;
	this->velocity.y = 0.f;
	this->velocityMax = 10.f;
	this->velocityMin = 0.3f;
	this->acceleration = 0.5f;
	this->drag = 0.9f;

}

Bat::~Bat()
{
}

const sf::Vector2f Bat::getPosition() const
{
	return this->sprite.getPosition();
}

sf::Vector2f Bat::getCenterPos()
{
	return sf::Vector2f();
}

const sf::FloatRect Bat::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

sf::Sprite Bat::getSprite()
{
	return this->sprite;
}

float Bat::getVelocityX()
{
	return this->velocity.x;
}

float Bat::getStartX()
{
	return this->startPos.x;
}

float Bat::getDestX()
{
	return this->destX;
}

void Bat::setVelocityX(float _velocity)
{
	this->velocity.x = _velocity;
}

void Bat::resetAnimationTimer()
{
	this->animationTimer.restart();
}

void Bat::updatePhysics()
{
	//Deceleration
	//this->velocity *= this->drag;

	//Limit Deceleration
	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
}

void Bat::updateAnimations()
{
	if (this->animState == BAT_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->currentFrame.top = 0;
			this->currentFrame.left += 16.f;
			if (this->currentFrame.left >= 80.f)
				this->currentFrame.left = 0.f;

			this->animationTimer.restart();
			this->sprite.setTextureRect(currentFrame);
		}
		this->sprite.setScale(2.5f, 2.5f);
		this->sprite.setOrigin(0.f, 0.f);
	}
	else if (this->animState == BAT_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->currentFrame.top = 0;
			this->currentFrame.left += 16.f;
			if (this->currentFrame.left >= 81.f)
				this->currentFrame.left = 0.f;

			this->animationTimer.restart();
			this->sprite.setTextureRect(currentFrame);
		}
		this->sprite.setScale(-2.5f, 2.5f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2.5f, 0.f);
	}
}

//_start denotes global X position of bat start location.
//_dest is relative x position to _start.
//Positive _dest means bat starts on left and goes right.
void Bat::updateMovement(float _start, float _dest)
{
	if (this->animState == BAT_LEFT)
	{
		if (this->sprite.getPosition().x <= _start && this->sprite.getPosition().x <= _start + _dest)
			this->setVelocityX(this->getVelocityX() + (this->acceleration * 2.f));
	}
	else if (this->animState == BAT_RIGHT)
	{
		if (this->sprite.getPosition().x >= _start && this->sprite.getPosition().x >= _start + _dest)
			this->setVelocityX(this->getVelocityX() + (this->acceleration * -2.f));
	}
	this->sprite.move(this->velocity);
}

void Bat::update(float _start, float _dest)
{
	this->updateAnimations();
	this->updateMovement(_start, _dest);
	this->updatePhysics();
}

void Bat::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
