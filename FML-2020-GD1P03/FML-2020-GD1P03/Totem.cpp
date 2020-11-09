#include "stdafx.h"
#include "Totem.h"

Totem::Totem(AnimationManager& a, Level& lev, int x, int y) :Entity(a, x, y)
{
	option("Totem", 0, "shoot");
}

void Totem::update(float time)
{
	anim.tick(time);
}
