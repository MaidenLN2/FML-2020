#include "stdafx.h"
#include "Acorn.h"

void Acorn::initTexture()
{
	//Load texture from file
	if (!texture.loadFromFile("Assets/Sprites/Food.png", sf::IntRect(300, 297, 26, 29)))
	{
		std::cout << "ERROR::Acorn::Assets/Sprites/Food.png failed to load." << "\n";
	}
}

void Acorn::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(1.f, 1.f);
}

Acorn::Acorn(float x, float y)
{
	this->initTexture();
	this->initSprite();
	sf::Vector2f pos;
	pos.x = x;
	pos.y = y;
	this->sprite.setPosition(pos);
}

Acorn::~Acorn()
{
}

const sf::Vector2f Acorn::getPosition() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Acorn::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Acorn::Update()
{
}

void Acorn::Render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
