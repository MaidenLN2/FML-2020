#pragma once
#include "stdafx.h"
#include "TileMap.h"
class SceneNode
{
protected:
    sf::Texture textureSheet1;
    sf::Texture textureSheet2;
    TileMap* levelMap;


public:
    // constructor
    SceneNode();
    SceneNode(int _level);

    // destructor - calls destroy
    virtual ~SceneNode();

    //Accessor
    TileMap* GetTileMap();

    //Functions
    // update our scene node
    void SceneInit(int _level);
    void Update(int _level);
    void Render(sf::RenderTarget& target);
};

