#include "stdafx.h"
#include "Projectile.h"

Projectile::Projectile(AnimationManager& a, Level& lev, int x, int y) :Entity(a, x, y)
{
	option("Fireball", 0.1, "moveLeft");
}

void Projectile::update(float time)
{
	x += dx * time;
	timer += time;
	if (timer > 3000) { dx *= -1; timer = 0; }
	if (dx < 0)
		anim.set("moveLeft");
	if (dx > 0)
		anim.set("moveRight");

	anim.tick(time);

}