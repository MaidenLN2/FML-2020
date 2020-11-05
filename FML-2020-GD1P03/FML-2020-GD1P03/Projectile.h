#pragma once
#include "Entity.h"

class Projectile : public Entity
{
public:
	Projectile(AnimationManager& a, Level& lev, int x, int y);

	void update(float time);
};