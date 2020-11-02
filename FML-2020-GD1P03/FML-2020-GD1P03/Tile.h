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
	const bool damaging;

public:
	Tile(sf::Texture& texture_sheet, sf::IntRect texture_rect, bool damaging = false);

	const sf::FloatRect getGlobalBounds() const;

	void update();
	void render(sf::RenderTarget& target);

};
