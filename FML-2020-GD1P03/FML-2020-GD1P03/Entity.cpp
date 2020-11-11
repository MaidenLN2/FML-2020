#include "stdafx.h"
#include "Entity.h"

using namespace sf;

Entity::Entity()
{
}

Entity::~Entity()
{
}

Entity::Entity(Image& image, float X, float Y, int W, int H, String Name)
{
	x = X; y = Y; w = W; h = H; name = Name; moveTimer = 0;
	speed = 0; health = 100; dx = 0; dy = 0;
	alive = true; onGround = false; isMove = false;
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setOrigin(w / 2, h / 2);
}