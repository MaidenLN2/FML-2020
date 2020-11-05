#include "stdafx.h"
#include "Platform.h"


Platform::Platform(AnimationManager& a, Level& lev, int x, int y) :Entity(a, x, y)
{
	option("Platform", 0.05, "move");
}

void Platform::update(float time)
{
	x += dx * time;
	timer += time;
	if (timer > 2000) { dx *= -1; timer = 0; }
	anim.tick(time);
}