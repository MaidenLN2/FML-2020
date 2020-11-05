#pragma once

#include "Entity.h"

class Platform : public Entity
{
public:
	Platform(AnimationManager& a, Level& lev, int x, int y);

	void update(float time);
};