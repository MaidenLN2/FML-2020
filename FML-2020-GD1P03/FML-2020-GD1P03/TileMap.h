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

	// Accessor
	std::vector<std::vector<Tile*>> GetTiles();

	void update();
	void render(sf::RenderTarget& target);
};

