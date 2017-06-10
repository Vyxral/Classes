#ifndef _SPRITEOBJECT_H_
#define _SPRITEOBJECT_H_

#define SERIE 1
#define PARALLELE 2

#include "cocos2d.h"


class SpriteObject
{

	private :
		cocos2d::Sprite *sprite;
		double scaleFactor;
		double rotateFactor;
		int priority;

		cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;


	public :
		SpriteObject();
		SpriteObject(std::string, double r=0.0, double s=1.0, int p=1);

		//Getter
		cocos2d::Sprite* getSprite();
		double getX();
		double getY();
		cocos2d::Vec2 getXY();

		void moveTo(cocos2d::Vec2);
		void moveTo(float x, float y);
		void moveBy(cocos2d::Vec2);
		void moveBy(float x, float y);

		//Image gestion
		void changeSprite(std::string);
		void scale(double);
		void rotate(double);
		void setPriority(int);

		//Action gestion
		void setAction(cocos2d::FiniteTimeAction*);
		void flush(int m=SERIE);
		void pause();
		void resume();



};


#endif