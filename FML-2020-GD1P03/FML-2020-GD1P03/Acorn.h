#pragma once
#include "stdafx.h"
class Acorn
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	// Core
	void initTexture();
	void initSprite();

public:
	Acorn(float x, float y);
	~Acorn();

	// Accessors
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;

	// Modifiers

	// Functions
	void Update();
	void Render(sf::RenderTarget& target);

};

