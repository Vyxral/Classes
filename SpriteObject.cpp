#include "SpriteObject.h"

SpriteObject::SpriteObject()
{
	sprite = cocos2d::Sprite::create("default.png");
	rotateFactor = 0.0;
	sprite->setRotation(0.0);
	scaleFactor = 1.0;
	sprite->setScale(1.0);
	priority = 0;

	actions = cocos2d::Vector<cocos2d::FiniteTimeAction*>();
}

SpriteObject::SpriteObject(std::string chemin, double r, double s, int p)
{
	sprite = cocos2d::Sprite::create(chemin);
	rotateFactor = r;
	sprite->setRotation((float)r);
	scaleFactor = s;
	sprite->setScale(s);
	priority = p;

	actions = cocos2d::Vector<cocos2d::FiniteTimeAction*>();
}

//Getter
cocos2d::Sprite* SpriteObject::getSprite()
{
	return sprite;
}

double SpriteObject::getX()
{
	return sprite->getPositionX();
}

double SpriteObject::getY()
{
	return sprite->getPositionY();
}

cocos2d::Vec2 SpriteObject::getXY()
{
	return sprite->getPosition();
}

void SpriteObject::moveBy(cocos2d::Vec2 v)
{
	sprite->setPosition(sprite->getPosition() + v);
}

void SpriteObject::moveBy(float x, float y)
{
	sprite->setPosition(sprite->getPosition() + cocos2d::Vec2(x, y));
}

void SpriteObject::moveTo(cocos2d::Vec2 v)
{
	sprite->setPosition(v);
}

void SpriteObject::moveTo(float x, float y)
{
	sprite->setPosition(cocos2d::Vec2(x, y));
}

//Image gestion
void SpriteObject::changeSprite(std::string c)
{
	sprite->setTexture(c);
}

void SpriteObject::scale(double s)
{
	sprite->setScale(s / scaleFactor);
	scaleFactor = s;
}

void SpriteObject::rotate(double r)
{
	sprite->setRotation(r - rotateFactor);
	rotateFactor = r;
}

void SpriteObject::setPriority(int p)
{
	priority = p;
}

//Action gestion
void SpriteObject::setAction(cocos2d::FiniteTimeAction* a)
{
	actions.pushBack(a);
}

void SpriteObject::flush(int mode)
{
	if (mode == PARALLELE)
	{
		auto action = cocos2d::Spawn::create(actions);
		if (sprite->getNumberOfRunningActions() == 0)
		{
			sprite->runAction(action);
			actions.clear();
		}
	}	
	else
	{
		auto action = cocos2d::Sequence::create(actions);
		if (sprite->getNumberOfRunningActions() == 0)
		{
			sprite->runAction(action);
			actions.clear();
		}
			
	}
	
}

void SpriteObject::pause()
{
	sprite->pause();
}

void SpriteObject::resume()
{
	sprite->resume();
}