#include "stdafx.h"
#include "TileMap.h"

TileMap::TileMap()
{
	//Initialise the TileMap
	std::vector<Tile*> layer1;
	tiles.push_back(layer1);
	std::vector<Tile*> layer2;
	tiles.push_back(layer2);
	std::vector<Tile*> layer3;
	tiles.push_back(layer3);

}

TileMap::~TileMap()
{
	for (int i = 0; i < 3; i++)
	{
			tiles[i].clear();
	}
	delete this;
}

void TileMap::addTile(unsigned x, unsigned y, sf::Texture& _texture, sf::IntRect texture_rect, int _layer, float scale)
{
	Tile* tile = new Tile(_texture, texture_rect, x, y, scale);
	tiles[_layer].push_back(tile);
}

std::vector<std::vector<Tile*>> TileMap::GetTiles()
{
	return tiles;
}


void TileMap::update()
{
}

void TileMap::render(sf::RenderTarget& target)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < this->tiles[i].size(); j++)
		{
			tiles[i].at(j)->render(target);
		}
	}
}
