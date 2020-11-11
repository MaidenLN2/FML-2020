#include "stdafx.h"
#include "Totem.h"
#include "Entity.h"

using namespace sf;

//void checkCollisionWithMap(float Dx, float Dy) //to see if enemy collides with map
//{
//	for (int i = y / 32; i < (y + h) / 32; i++)// map elements check
//		for (int j = x / 32; j < (x + w) / 32; j++)
//		{
//			if (TileMap[i][j] == '0')// it's ground tile
//			{
//				if (Dy > 0) { y = i * 32 - h; }// moving about y-axis (fall/jump)
//				if (Dy < 0) { y = i * 32 + 32; }// upper map limit collision
//				if (Dx > 0) { x = j * 32 - w; dx = -0.1; sprite.scale(-1, 1); }// right map limit collision
//				if (Dx < 0) { x = j * 32 + 32; dx = 0.1; sprite.scale(-1, 1); }// left map limit collision
//			}
//		}
//}
//
//void update(float time)
//{
//	if (name == "Totem")
//	{
//
//		checkCollisionWithMap(dx, 0);// checking collision about x-axis
//		x += dx * time;
//		sprite.setPosition(x + w / 2, y + h / 2); //sprite centered
//		if (health <= 0)
//		{
//			alive = false;
//		}
//	}
//}
