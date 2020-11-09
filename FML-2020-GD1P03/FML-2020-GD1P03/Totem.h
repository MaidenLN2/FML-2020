#pragma once
#include "Entity.h"

class Totem : public Entity
{
public:
	Totem(AnimationManager& a, Level& lev, int x, int y);
	void update(float time);
};

