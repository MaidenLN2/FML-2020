#pragma once
#include "stdafx.h"
class background
{
private:
	sf::Sprite sBGSky;
	sf::Sprite sBGMountains1;
	sf::Sprite sBGMountains2;
	sf::Sprite sBGTrees;
	sf::Texture BGSky;
	sf::Texture BGMountains1;
	sf::Texture BGMountains2;
	sf::Texture BGTrees;
	

	void initTextures();
	void initSprites();

public:
	background();
	~background();

	void render(sf::RenderTarget& target);
};

