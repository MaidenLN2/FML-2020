#pragma once
class CDOFNode : public CSceneNode
{
public:
    CDOFNode() { }
    ~CDOFNode() { }

    void Initialize(float m[4][4])
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                m_fvMatrix[i][j] = m[i][j];
    }

    void Update()
    {
        glPushMatrix();
        glLoadMatrix((float*)m_fvMatrix);

        CSceneNode::Update();

        glPopMatrix();
    }

private:
    float m_fvMatrix[4][4];
};