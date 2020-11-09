#pragma once
class GeometryNode
{
public:
	CGeometryNode() { }
	~CGeometryNode() { }

	void Update()
	{
		// Draw our geometry here!

		CSceneNode::Update();
	}
};

