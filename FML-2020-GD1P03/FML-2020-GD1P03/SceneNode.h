#pragma once
#include "stdafx.h"
#include "TileMap.h"
#include "Acorn.h"
class SceneNode
{
protected:
    sf::Texture textureSheet1;
    sf::Texture textureSheet2;
    TileMap* levelMap;
    Acorn* acorn;


public:
    // constructor
    SceneNode();
    SceneNode(int _level);

    // destructor - calls destroy
    virtual ~SceneNode();

    //Accessor
    TileMap* GetTileMap();
    Acorn* getAcorn();
    sf::Vector2f GetAcornPos();

    //Functions
    // update our scene node
    void SceneInit(int _level);
    void Update(int _level);
    void Render(sf::RenderTarget& target);
};

