#pragma once


#include "cocos2d.h"
#include "Ship.h"

class Bullet
{
	private :
		cocos2d::Vec2 position;
		cocos2d::Vec2 direction;
		float velocity;
		float power;
		Ship* owner;

	public :
		Bullet();
		Bullet(cocos2d::Vec2, cocos2d::Vec2, float, float);

		cocos2d::Vec2 getPosition();
		cocos2d::Vec2 getDirection();
		float getVelocity();
		float getPower();

		void update(float delta);


};