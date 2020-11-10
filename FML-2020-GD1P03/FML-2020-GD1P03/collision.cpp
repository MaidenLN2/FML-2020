#include "stdafx.h"
#include "collision.h"
#include"Player.h"
#include"Totem.h"
#include"Projectile.h"
#include"Tile.h"
#include<iostream>

using namespace std;

// Player goes SLAM with enemy
bool collision::collidesWith(Player& obj1, Enemy& obj2)
{
    // Bounding box of player
    sf::FloatRect Player;
   
    // Bounding box of enemy
    sf::FloatRect Enemy;

    if (Player.intersects(Enemy))
    {
        bool Player(false);
        cout << "YOU DIED" << endl;
        // migh shove YOU DIED pic if we have time
    }

    else
    {
        bool Player(true);
    }

    return Player.intersects(Enemy);
}

bool collision::collidesWith(Projectile& obj1, Player& obj2)

// Projectile kills sqirrel, F

{
    // Bounding box of projectile
    sf::FloatRect Projectile;

    // Bounding box of player
    sf::FloatRect Player;

    if (Projectile.intersects(Player))
    {
        bool Player(false);
        cout << "YOU DIED" << endl;
        // migh shove YOU DIED pic if we have time
    }

    else
    {
        bool Player(true);
    }

    return Projectile.intersects(Player);
}
bool collision::collidesWith(Tile& obj1, Player& obj2)
{
    // Bounding box of tile 
    sf::FloatRect Tile;

    //Bounding box of player
    sf::FloatRect Player;


    if (Tile.intersects(Player)) // not working
    {
        // player stays on tile? gravity?
        bool Tile(true);
        bool Player(true);
    }

    else
    {
        bool Tile(true);
        bool Player(true);
    }

    return Tile.intersects(Player);
}