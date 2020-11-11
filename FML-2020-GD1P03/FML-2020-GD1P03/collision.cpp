#include "stdafx.h"
#include "collision.h"
#include "Player.h"

// Player goes SLAM with enemy
//bool collision::collidesWith(Player&, Enemy&)
//{
//    // Bounding box of player
//    sf::FloatRect Player;
//
//    // Bounding box of enemy
//    sf::FloatRect Enemy;
//
//    if (Player.intersects(Enemy))
//    {
//        bool Player(false);
//        std::cout << "YOU DIED" << std::endl;
//        // migh shove YOU DIED pic if we have time
//    }
//
//    else
//    {
//        bool Player(true);
//    }
//
//    return Player.intersects(Enemy);
//}
//
//bool collision::collidesWith(Player&, Totem&)
//{
//    // Bounding box of player
//    sf::FloatRect Player;
//
//    // Bounding box of totem
//    sf::FloatRect Totem;
//
//    if (Player.intersects(Totem))
//    {
//        bool Player(false);
//        std::cout << "YOU DIED" << std::endl;
//        // migh shove YOU DIED pic if we have time
//    }
//
//    else
//    {
//        bool Player(true);
//    }
//
//    return Player.intersects(Totem);
//}
//
//bool collision::collidesWith(Projectile& obj1, Player& obj2) 
//
//// Projectile kills sqirrel, F
//{
//    // Bounding box of projectile
//    sf::FloatRect Projectile;
//
//    // Bounding box of player
//    sf::FloatRect Player;
//
//    if (Projectile.intersects(Player))
//    {
//        bool Player(false);
//        std::cout << "YOU DIED" << std::endl;
//        // migh shove YOU DIED pic if we have time
//    }
//
//    else
//    {
//        bool Player(true);
//    }
//
//    return Projectile.intersects(Player);
//}
//bool collision::collidesWith(Tile& obj1, Player& obj2)
//{
//    // Bounding box of tile 
//    sf::FloatRect Tile;
//
//    //Bounding box of player
//    sf::FloatRect Player;
//
//
//    if (Tile.intersects(Player)) // not working
//    {
//        // player stays on tile? gravity?
//        bool Tile(true);
//        bool Player(true);
//    }
//
//    else
//    {
//        bool Tile(true);
//        bool Player(true);
//    }
//
//    return Tile.intersects(Player);
//}
//
//bool collidesWith(Tile& obj1, Player& obj2)
//{
//    return false;
//}

//for (unsigned int i = 0; i <= solidObjects.size() - 1; i++)
//{
//    if (solidObjects[i].getGlobalBounds().intersects(Player.getGlobalBounds()))
//    {
//        if (Player.getPosition().x - solidObjects[i].getPosition().x < Player.getPosition().y - solidObjects[i].getPosition().y)
//        {
//            Player.setPosition(solidObjects[i].getPosition().x - Player.getOrigin().x, SuperMario.getPosition().y);
//            IsTouching = false;
//        }
//        else if (Player.getPosition().y - solidObjects[i].getPosition().y < Player.getPosition().x - solidObjects[i].getPosition().x)
//        {
//            Player.setPosition(Player.getPosition().x, solidObjects[i].getPosition().y - Player.getOrigin().y);
//            IsTouching = true;
//        }
//        else if (Player.getPosition().x - solidObjects[i].getTextureRect().width < Player.getPosition().y - solidObjects[i].getPosition().y)
//        {
//            Player.setPosition(solidObjects[i].getTextureRect().width + Player.getOrigin().x, Player.getPosition().y);
//            IsTouching = false;
//        }
//    }
//    else
//    {
//        IsTouching = false;
//    }
//}

//Tile platform(texture_sheet, texture_rect, x, y, scale);
//platform.getGlobalBounds().intersects(rect.GlobalBounds))
//

bool collision(sf::Sprite Tile)
{
    this->setBounds();
    Tile.getGlobalBounds();

    if (top > Tile.bottom || bottom < sprite2.top || left > sprite2.right || right < sprite2.left)
    {
        return false;
    }

    return true;
}


void colMove(sf::Vector2f& movement, Tile sprite2)
{
    if (!this->collision(Tile))
    {
        this->move(movement);
    }
}

void colMove(float x, float y, sf::Sprite sprite2)
{
    if (!this->collision(sprite2))
    {
        this->move(x, y);
    }
}

void setBounds()
{
    top = this->getPosition().y;
    bottom = this->getPosition().y + this->getTexture()->getSize().y;
    left = this->getPosition().x;
    right = this->getPosition().x + this->getTexture()->getSize().y;
}
