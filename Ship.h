#pragma once

#include "cocos2d.h"
#include "Bullet.h"

class Ship
{

	private :
		float hp;
		cocos2d::Vec2 position;
		cocos2d::Vec2 firingPosition;


	public :
		Ship();
		Ship(float, cocos2d::Vec2, cocos2d::Vec2);
		Ship(float, float, float, float, float);

		float getHp();
		cocos2d::Vec2 getPosition();
		cocos2d::Vec2 getFiringPosition();

		void setHp(float);
		void setPosition(float, float);
		void setPosition(cocos2d::Vec2);
		void setFiringPosition(float, float);
		void setFiringPosition(cocos2d::Vec2);

		void removeHp(float);
		void moveX(float);
		void moveY(float);
		bool isDead();

		void applyChangeToSprite(cocos2d::Sprite*);
		void IA(float);

};