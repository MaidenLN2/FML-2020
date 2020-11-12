#pragma once
#include "Enemy.h".
//#include "Player.h"
#include "Totem.h"
#include "Projectile.h"
#include "Tile.h"
#include "stdafx.h"

// Creating class collision between objects I shoved up my code

class collision
{
public:
    /*static bool collidesWith(Player&, Enemy&);
    static bool collidesWith(Player&, Totem&);
    static bool collidesWith(Projectile&, Player&);
    static bool collidesWith(Tile& obj1, Player& obj2);*/

    Vector2<bool> collisionCheck(sf::Sprite Defending, sf::Sprite Attacking);
    Vector2<bool> collisionCheck(sf::Sprite Defending, sf::FloatRect AttackingGlobalBounds);
    //void colMove(sf::Vector2f& movement, Tile sprite2);
    //void collisionMove(const float x, const float y, sf::Sprite Defending, sf::Sprite Attacking);
    //void setBounds();

private:

};

