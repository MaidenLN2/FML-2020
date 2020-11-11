#pragma once
#include "Enemy.h".
#include "Player.h"
#include "Totem.h"
#include "Projectile.h"
#include "Tile.h"
#include "stdafx.h"
#include "Player.h"

// Creating class collision between objects I shoved up my code

class collision
{
public:
    static bool collidesWith(Player&, Enemy&);
    static bool collidesWith(Player&, Totem&);
    static bool collidesWith(Projectile&, Player&);
    static bool collidesWith(Tile& obj1, Player& obj2);

   

private:

};
bool collision(sf::Sprite Tile);
void colMove(sf::Vector2f& movement, Tile sprite2);
void colMove(float x, float y, sf::Sprite sprite2);
void setBounds();
