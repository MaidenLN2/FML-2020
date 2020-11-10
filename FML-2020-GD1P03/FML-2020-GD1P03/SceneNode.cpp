#include "stdafx.h"
#include "SceneNode.h"

void SceneNode::SceneInit()
{
}

SceneNode::SceneNode(int _level)
{
	switch (_level)
	{
		case 0:
		{
			// Logic for Level 1
		}
		case 1:
		{
			// Logic for level 2
		}
	}
}

SceneNode::~SceneNode()
{
}

void SceneNode::Update()
{
}

void SceneNode::Render(sf::RenderTarget& target)
{
}
