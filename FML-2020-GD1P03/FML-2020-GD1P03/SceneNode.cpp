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
	case 0: //Level 1 tile layout
	{
		// initialise Tiles
		//border
		int xPos = 0;
		for (int i = 0; i < 11; i++)
		{
			this->levelMap->addTile(xPos, 0, textureSheet1, sf::IntRect(16, 80, 48, 15), 0, 1.52f);
			xPos += 73;
		}
		int yPos = 23;
		for (int i = 0; i < 8; i++)
		{
			this->levelMap->addTile(0, yPos, textureSheet1, sf::IntRect(80, 80, 15, 48), 0, 1.52f);
			yPos += 73;
		}
		yPos = 23;
		for (int i = 0; i < 8; i++)
		{
			this->levelMap->addTile(777, yPos, textureSheet1, sf::IntRect(80, 80, 15, 48), 0, 1.52f);
			yPos += 73;
		}
		xPos = 0;
		for (int i = 0; i < 11; i++)
		{
			this->levelMap->addTile(xPos, 577, textureSheet1, sf::IntRect(16, 80, 48, 15), 0, 1.52f);
			xPos += 73;
		}

		//platforms
		xPos = 254;
		for (int i = 0; i < 4; i++)
		{
			this->levelMap->addTile(xPos, 120, textureSheet1, sf::IntRect(16, 80, 48, 15), 0, 1.52f);
			xPos += 73;
		}
		xPos = 23;
		for (int i = 0; i < 4; i++)
		{
			this->levelMap->addTile(xPos, 420, textureSheet1, sf::IntRect(16, 80, 48, 15), 0, 1.52f);
			xPos += 73;
		}
		xPos = 485;
		for (int i = 0; i < 4; i++)
		{
			this->levelMap->addTile(xPos, 420, textureSheet1, sf::IntRect(16, 80, 48, 15), 0, 1.52f);
			xPos += 73;
		}
		xPos = 96;
		for (int i = 0; i < 2; i++)
		{
			this->levelMap->addTile(xPos, 220, textureSheet1, sf::IntRect(16, 80, 48, 15), 0, 1.52f);
			xPos += 73;
		}
		xPos = 558;
		for (int i = 0; i < 2; i++)
		{
			this->levelMap->addTile(xPos, 220, textureSheet1, sf::IntRect(16, 80, 48, 15), 0, 1.52f);
			xPos += 73;
		}
		this->levelMap->addTile(364, 504, textureSheet1, sf::IntRect(80, 16, 48, 48), 0, 1.52f);
		// initialise Enemies
		Bat* bat = new Bat(100.f, 100.f, 200.f);
		this->bats.push_back(bat);

		// initialise Win Destination
		acorn = new Acorn(750.f, 525.f);

		// Set Player start position
		break;
	}
	case 1: //Level 2 tile layout
	{
		// initialise Tiles
		//border
		int xPos = 0;
		for (int i = 0; i < 11; i++)
		{
			this->levelMap->addTile(xPos, 0, textureSheet2, sf::IntRect(16, 80, 48, 15), 0, 1.52f);
			xPos += 73;
		}
		int yPos = 23;
		for (int i = 0; i < 8; i++)
		{
			this->levelMap->addTile(0, yPos, textureSheet2, sf::IntRect(80, 80, 15, 48), 0, 1.52f);
			yPos += 73;
		}
		yPos = 23;
		for (int i = 0; i < 8; i++)
		{
			this->levelMap->addTile(777, yPos, textureSheet2, sf::IntRect(80, 80, 15, 48), 0, 1.52f);
			yPos += 73;
		}
		xPos = 0;
		for (int i = 0; i < 11; i++)
		{
			this->levelMap->addTile(xPos, 577, textureSheet2, sf::IntRect(16, 80, 48, 15), 0, 1.52f);
			xPos += 73;
		}

		//platforms
		
		// initialise Enemies

		// initialise Win Destination
		acorn = new Acorn(750.f, 525.f);

		// Set Player start position
		break;
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
	this->levelMap->~TileMap();
	// remove enemies
	// remove this scenenode
	delete this;
}

TileMap* SceneNode::GetTileMap()
{
	return levelMap;
}

Acorn* SceneNode::getAcorn()
{
	return this->acorn;
}

sf::Vector2f SceneNode::GetAcornPos()
{
	sf::Vector2f pos;
	pos.x = this->acorn->getGlobalBounds().left + (this->acorn->getGlobalBounds().width / 2);
	pos.y = this->acorn->getGlobalBounds().top + (this->acorn->getGlobalBounds().height / 2);
	return pos;
}

std::vector<Bat*> SceneNode::getBats()
{
	return this->bats;
}

void SceneNode::Update()
{
	for (int i = 0; i < bats.size(); i++)
	{
		bats.at(i)->update(bats.at(i)->getStartX(), bats.at(i)->getDestX());
	}
}

void SceneNode::Render(sf::RenderTarget& target)
{
	this->levelMap->render(target);
	this->acorn->Render(target);
	for (int i = 0 ; i < bats.size(); i++)
	{
		bats.at(i)->render(target);
	}
}
