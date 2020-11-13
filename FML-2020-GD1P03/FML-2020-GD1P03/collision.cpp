#include "stdafx.h"
#include "collision.h"

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

Vector2<bool> collision::collisionCheck(sf::Sprite Defending, sf::Sprite Attacking)
{
    //setBounds();
    // Defending sprite's global bounds and associated functions
    sf::FloatRect DefendingBounds = Defending.getGlobalBounds();
    auto DefendingBoundsBottom = (DefendingBounds.top - DefendingBounds.height);
    auto DefendingBoundsRight = (DefendingBounds.left + DefendingBounds.width);

    // Attacking sprite's global bounds and associated functions
    sf::FloatRect AttackingBounds = Attacking.getGlobalBounds();
    auto AttackingBoundsBottom = (AttackingBounds.top - AttackingBounds.height);
    auto AttackingBoundsRight = (AttackingBounds.left + AttackingBounds.width);

    Vector2<bool> Check(0, 0);

    if (DefendingBounds.left < AttackingBoundsRight && DefendingBounds.left > AttackingBounds.left || 
        DefendingBoundsRight > AttackingBounds.left && DefendingBoundsRight < AttackingBoundsRight) // Check for x collision first
    {
        Check.x = 1; // 1 Represents a collision on the x-axis
    }
    
    if ((DefendingBounds.top < AttackingBoundsBottom && DefendingBounds.top > AttackingBounds.top ||
        DefendingBoundsBottom > AttackingBounds.top && DefendingBoundsBottom < AttackingBoundsBottom)) // Check for y collision second
    {
        Check.y = 1;  // 1 Represents a collision on the y-axis
    }
    if (Check == sf::Vector2<bool>(1, 1))
        std::cout << "Collision \n";
    return Check;
}

Vector2<bool> collision::collisionCheck(sf::Sprite Defending, sf::FloatRect AttackingGlobalBounds)
{
    //setBounds();

    // Defending sprite's global bounds and associated functions
    sf::FloatRect DefendingBounds = Defending.getGlobalBounds();
    auto DefendingBoundsBottom = (DefendingBounds.top - DefendingBounds.height);
    auto DefendingBoundsRight = (DefendingBounds.left + DefendingBounds.width);

    // Attacking sprite's global bounds and associated functions
    auto AttackingBoundsBottom = (AttackingGlobalBounds.top - AttackingGlobalBounds.height);
    auto AttackingBoundsRight = (AttackingGlobalBounds.left + AttackingGlobalBounds.width);

    Vector2<bool> Check(0, 0);

    if (DefendingBounds.left > AttackingBoundsRight || DefendingBoundsRight < AttackingGlobalBounds.left) // Check for x collision first
    {
        Check.x = true; // True represents a collision on the x-axis
    }

    if ((DefendingBounds.top > AttackingBoundsBottom || DefendingBoundsBottom < AttackingGlobalBounds.top)) // Check for y collision second
    {
        Check.y = true;  // True represents a collision on the y-axis
    }

    return Check;
}


//void collision::colMove(sf::Vector2f& movement, Tile sprite2)
//{
//    if (!collisionCheck(sprite2.GetSprite(), ))
//    {
//        move(movement);
//    }
//}

//void setBounds()
//{
//    top = this->getPosition().y;
//    bottom = this->getPosition().y + this->getTexture()->getSize().y;
//    left = this->getPosition().x;
//    right = this->getPosition().x + this->getTexture()->getSize().y;
//}
