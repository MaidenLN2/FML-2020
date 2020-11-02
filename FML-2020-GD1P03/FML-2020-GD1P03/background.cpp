#include "stdafx.h"
#include "background.h"


void background::initTextures()
{
	if (!BGSky.loadFromFile("Assets/Background/sky-bg.png"))
		std::cout << "ERROR::BACKGROUND::Assets/Background/sky-bg.png failed to load." << "\n";
	if (!BGMountains1.loadFromFile("Assets/Background/mountain1-bg.png"))
		std::cout << "ERROR::BACKGROUND::Assets/Background/mountain1-bg.png failed to load." << "\n";
	if (!BGMountains2.loadFromFile("Assets/Background/mountain2-bg.png"))
		std::cout << "ERROR::BACKGROUND::Assets/Background/mountain2-bg.png failed to load." << "\n";
	if (!BGTrees.loadFromFile("Assets/Background/trees-bg.png"))
		std::cout << "ERROR::BACKGROUND::Assets/Background/trees-bg.png failed to load." << "\n";
	}

void background::initSprites()
{
	this->sBGSky.setTexture(this->BGSky);
	this->sBGMountains1.setTexture(this->BGMountains1);
	this->sBGMountains2.setTexture(this->BGMountains2);
	this->sBGTrees.setTexture(this->BGTrees);

	this->sBGSky.setTextureRect(sf::IntRect(0,0,272,160));
	this->sBGMountains1.setTextureRect(sf::IntRect(0,0,272,160));
	this->sBGMountains2.setTextureRect(sf::IntRect(0,0,272,160));
	this->sBGTrees.setTextureRect(sf::IntRect(0,0,272,160));

	this->sBGSky.setScale(3.0f, 3.0f);
	this->sBGMountains1.setScale(3.0f, 3.0f);
	this->sBGMountains2.setScale(3.0f, 3.0f);
	this->sBGTrees.setScale(3.0f, 3.0f);

	this->sBGSky.setPosition(0, 0);
	this->sBGMountains1.setPosition(0, 100);
	this->sBGMountains2.setPosition(0, 150);
	this->sBGTrees.setPosition(0, 120);
}

background::background()
{
	this->initTextures();
	this->initSprites();
}

background::~background()
{
}

void background::render(sf::RenderTarget& target)
{
	target.draw(this->sBGSky);
	target.draw(this->sBGMountains1);
	target.draw(this->sBGMountains2);
	target.draw(this->sBGTrees);
}
