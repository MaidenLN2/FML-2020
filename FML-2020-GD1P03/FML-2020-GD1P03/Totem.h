#pragma once
#include "stdafx.h"
#include "TileMap.h"
#include "vector"
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Totem :public Entity //yes we do need entity class
{
public:
	Totem(Image& image, float X, float Y, int W, int H, String Name) :Entity(image, X, Y, W, H, Name)
	{
		if (name == "Totem")
		{
			sprite.setTextureRect(IntRect(0, 0, w, h));
			dx = 0.1;// speed, dat shit moves
		}
	}

};

