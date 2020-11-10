#include "stdafx.h"
#include "SceneNode.h"

void SceneNode::SceneInit(int _level)
{
	levelMap = new TileMap;
	if (!this->textureSheet1.loadFromFile("Assets/Tilesets/Dungeon Ruins Tileset Day.png"))
		std::cout << "ERROR::SCENENODE::Assets/Tilesets/Dungeon Ruins Tileset Day.png failed to load." << "\n";
	if (!this->textureSheet2.loadFromFile("Assets/Tilesets/Dungeon Ruins Tileset Night.png"))
		std::cout << "ERROR::SCENENODE::Assets/Tilesets/Dungeon Ruins Tileset Night.png failed to load." << "\n";
	
	switch (_level)
	{
	case 0:
	{
		// initialise Tiles
		int xPos = 0;
		for (int i = 0; i < 5; i++)
		{
			this->levelMap->addTile(xPos, 500, textureSheet1, sf::IntRect(16, 80, 48, 15), 0, 1.5f);
			xPos += 72;
		}
		// initialise Enemies

		// initialise Win Destination

		// Set Player start position
	}
	case 1:
	{
		// initialise Tiles

		// initialise Enemies

		// initialise Win Destination

		// Set Player start position
	}
	}
}

SceneNode::SceneNode()
{
}

SceneNode::SceneNode(int _level)
{
	SceneInit(_level);	
}

SceneNode::~SceneNode()
{
	// remove Tiles from TileMap
	// remove TileMap
	// remove enemies
	// remove this scenenode
}

void SceneNode::Update(int _level)
{
	
}

void SceneNode::Render(sf::RenderTarget& target)
{
	this->levelMap->render(target);
}
