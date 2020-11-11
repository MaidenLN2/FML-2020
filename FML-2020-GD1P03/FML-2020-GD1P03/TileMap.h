#pragma once
#include "Tile.h"

class TileMap
{
private:
	std::vector<std::vector<Tile*>> tiles;

public:
	TileMap();
	~TileMap();

	//Functions
	void addTile(unsigned x, unsigned y, sf::Texture& _texture, sf::IntRect texture_rect, int _layer, float scale);

	void update();
	void render(sf::RenderTarget& target);
};

