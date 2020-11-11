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

	Enemy();
	virtual ~Enemy();
	Enemy(Image& image, float X, float Y, int W, int H, String Name);

	

	
};