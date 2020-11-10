#pragma once

#include "stdafx.h"

using namespace sf;

class Entity
{
public:
	float dx, dy, x, y, speed, moveTimer;// adding timer
	int w, h, health;
	bool alive, isMove, onGround;
	Texture texture;
	Sprite sprite;
	String name;// enemies have names, Enemy and Totem
	Entity(Image& image, float X, float Y, int W, int H, String Name);
	//{
	//	x = X; 
	//	y = Y; 
	//	w = W; 
	//	h = H; 
	//	name = Name; 
	//	moveTimer = 0;
	//	speed = 0; 
	//	health = 100; 
	//	dx = 0; 
	//	dy = 0;
	//	alive = true; 
	//	onGround = false; 
	//	isMove = false;
	//	texture.loadFromImage(image);
	//	sprite.setTexture(texture);
	//	sprite.setOrigin(w/2, h/2);
	//}
};

