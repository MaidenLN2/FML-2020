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
bool sf::Player::collision(sf::Sprite Tile)
{
    this->setBounds();
    Tile.getGlobalBounds();

    if (top > Tile.bottom || bottom < sprite2.top || left > sprite2.right || right < sprite2.left) 
    {
        return false;
    }

    return true;
}

void sf::Player::colMove(sf::Vector2f& movement, sf::Tile sprite2) 
{
    if (!this->collision(Tile)) 
    {
        this->move(movement);
    }
}

void sf::Sprite::colMove(float x, float y, sf::Sprite sprite2) 
{
    if (!this->collision(sprite2)) 
    {
        this->move(x, y);
    }
}

void sf::Player::setBounds() {
    top = this->getPosition().y;
    bottom = this->getPosition().y + this->getTexture()->getSize().y;
    left = this->getPosition().x;
    right = this->getPosition().x + this->getTexture()->getSize().y;
}