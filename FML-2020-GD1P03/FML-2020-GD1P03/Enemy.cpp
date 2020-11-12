#include "stdafx.h"
#include "Enemy.h"
#include "Entity.h"

using namespace sf;


//void checkCollisionWithMap(float Dx, float Dy) //to see if enemy collides with map
//{
//	for (int i = y / 32; i < (y + h) / 32; i++)// map elements check
//		for (int j = x / 32; j < (x + w) / 32; j++)
//		{
//			if (TileMap[i][j] == '0') // it's ground tile
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
//	if (name == "Bat")
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

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

Enemy::Enemy(Image& image, float X, float Y, int W, int H, String Name)
	: Entity(image, X, Y, W, H, Name)
{
	if (name == "Bat")
	{
		sprite.setTextureRect(IntRect(0, 0, w, h));
		dx = 0.1;// speed, dat shit moves
	}
}

//void Move()
//{
//    // movement
//    Vector2f playerPosition = Enemy::Entity().Player.getPosition();
//    Vector2f thisPosition;
//    thisPosition.x = xPos;
//    thisPosition.y = yPos;
//  
//    speed = 5;
//}
//
//Vector2f normalize(const Vector2f& source)
//{
//    float length = sqrt((source.x * source.x) + (source.y * source.y));
//    if (length != 0)
//        return Vector2f(source.x / length, source.y / length);
//    else
//        return source;
//}