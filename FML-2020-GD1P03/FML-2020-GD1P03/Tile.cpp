//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2020 Media Design School
//
// File Name	: Tile.cpp
// Description	: Definition file for a Tile piece
// Author		: Callum Boyce
//				: Lera Blokhina
// Mail			: callum.boyce@mds.ac.nz
//				: valeriia.blokhina@mds.ac.nz
//

#include "stdafx.h"
#include "Tile.h"

Tile::Tile(sf::Texture& texture_sheet, sf::IntRect texture_rect, unsigned x, unsigned y, float scale)
{
	this->sprite.setTexture(texture_sheet);
	this->sprite.setTextureRect(texture_rect);
	this->sprite.setPosition(x, y);
	this->sprite.setScale(scale, scale);
}

const sf::FloatRect Tile::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

sf::Sprite Tile::GetSprite()
{
	return sprite;
}

void Tile::update()
{
}

void Tile::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
