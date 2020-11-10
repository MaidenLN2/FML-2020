#pragma once
#include "stdafx.h"
#include "TileMap.h"
#include "vector"
//#include <SFML/Graphics.hpp>
#include "Entity.h"


class Enemy :public Entity //yes we do need entity class

{
private:
	int dx;
	int dy;

public:

	int x;
	int y;
	int h;
	int w;


	Enemy(Image& image, float X, float Y, int W, int H, String Name) : Entity(image, X, Y, W, H, Name) 
	{
		if (name == "Bat") 
		{
			sprite.setTextureRect(IntRect(0, 0, w, h));
			dx = 0.1;// speed, dat shit moves
		}
	}

	
};