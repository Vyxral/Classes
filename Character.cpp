#include "Character.h"

Character::Character()
{
	sprite = cocos2d::Sprite::create("default.png");
	sprite->setPosition(0.0f, 0.0f);
}

Character::Character(float x, float y)
{
	sprite = cocos2d::Sprite::create("default.png");
	sprite->setPosition(x, y);
}

Character::Character(float x, float y, std::string chemin)
{
	sprite = cocos2d::Sprite::create(chemin);
	sprite->setPosition(x, y);
}


cocos2d::Vec2 Character::getCoordonates()
{
	return sprite->getPosition();
}

cocos2d::Sprite* Character::getSprite()
{
	return sprite;
}

void Character::setCoordonates(float x, float y)
{
	sprite->setPosition(x, y);
}

void Character::setSprite(std::string chemin)
{
	sprite = cocos2d::Sprite::create("chemin");
}
