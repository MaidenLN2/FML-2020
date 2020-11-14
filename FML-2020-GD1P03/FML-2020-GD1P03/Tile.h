//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2020 Media Design School
//
// File Name	: Tile.h
// Description	: Declaration file for a Tile piece
// Author		: Callum Boyce
//				: Lera Blokhina
// Mail			: callum.boyce@mds.ac.nz
//				: valeriia.blokhina@mds.ac.nz
//

#pragma once
class Tile
{
private:
	sf::Sprite sprite;
	sf::Vector2f centerPos;

public:
	Tile(sf::Texture& texture_sheet, sf::IntRect texture_rect, unsigned x, unsigned y, float scale);

	const sf::FloatRect getGlobalBounds() const;
	const sf::Vector2f getCenterPos() const;

	sf::Sprite GetSprite();

	void update();
	void render(sf::RenderTarget& target);

};

