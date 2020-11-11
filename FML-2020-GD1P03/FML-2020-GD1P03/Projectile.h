#pragma once
#include "Entity.h"
#include "TileMap.h"

class Projectile : public Entity
{
public:
	Projectile();
	virtual ~Projectile();
	//	Projectile(initAnimations()& a, TileMap& lev, int x, int y);

	//	void update(float time);
};