#pragma once
#include "stdafx.h"
#include "TileMap.h"
class SceneNode
{
protected:
    sf::Texture textureSheet;
    TileMap levelMap;

    void SceneInit();
public:
    // constructor
    SceneNode(int _level);

    // destructor - calls destroy
    virtual ~SceneNode();


    //Functions
    // update our scene node
    void Update();
    void Render(sf::RenderTarget& target);
};

