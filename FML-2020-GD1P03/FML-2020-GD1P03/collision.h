#pragma once
#include"Enemy.h".
#include"Player.h"
#include"Totem.h"
#include"Projectile.h"
#include"Tile.h"

// Creating class collision between objects I shoved up my code

class collision

    // Constructor - events that are happening (squirrel jumps, collides, dies!)
{
public:
    static bool collidesWith(Player&, Enemy&);
    static bool collidesWith(Player&, Totem&);
    static bool collidesWith(Projectile&, Player&);
    static bool collidesWith(Tile& obj1, Player& obj2);

private:
};
