#pragma once
#include"Animation.h"
#include"Level.h"

//class AnimationManager
//{
//
//public:
//	std::string currentAnim;
//	std::map<std::string, Animation> animList;
//
//	AnimationManager();
//
//	~AnimationManager();
//
//	void loadFromXML(std::string fileName, Texture& t);
//
//	void set(std::string name);
//
//	void draw(RenderWindow& window, int x, int y);
//
//	void flip(bool b);
//
//	void tick(float time);
//
//	void pause();
//
//	void play();
//
//	void play(std::string name);
//
//	bool isPlaying();
//
//	float getH();
//
//	float getW();
//
//};
class Enemy
{
public:

	Enemy(AnimationManager& a, Level& lev, int x, int y);
	void update(float time);
	void Collision(float Dx, float Dy);
};


