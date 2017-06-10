#include "Ship.h"


Ship::Ship()
{
	this->hp = 200;
	this->position = cocos2d::Vec2(500.f, 700.f);
	this->firingPosition = cocos2d::Vec2(500.f, 700.f);
}

Ship::Ship(float m_hp, cocos2d::Vec2 v, cocos2d::Vec2 f)
{
	this->hp = m_hp;
	this->position = v;
	this->firingPosition = f;
}

Ship::Ship(float m_hp, float m_x, float m_y, float m_z, float m_w)
{
	this->hp = m_hp;
	this->position = cocos2d::Vec2(m_x, m_y);
	this->firingPosition = cocos2d::Vec2(m_z, m_w);
}

float Ship::getHp()
{
	return this->hp;
}

cocos2d::Vec2 Ship::getPosition()
{
	return this->position;
}

cocos2d::Vec2 Ship::getFiringPosition()
{
	return this->firingPosition;
}

void Ship::setHp(float m_hp)
{
	this->hp = m_hp;
}

void Ship::setPosition(float m_x, float m_y)
{
	this->position = cocos2d::Vec2(m_x, m_y);
}

void Ship::setPosition(cocos2d::Vec2 v)
{
	this->position = v;
}

void Ship::setFiringPosition(float m_x, float m_y)
{
	this->firingPosition = cocos2d::Vec2(m_x, m_y);
}

void Ship::setFiringPosition(cocos2d::Vec2 v)
{
	this->firingPosition = v;
}

void Ship::removeHp(float m_hp)
{
	this->hp -= m_hp;
}

void Ship::moveX(float m_x)
{
	this->position.x += m_x;
	this->firingPosition.x += m_x;
}

void Ship::moveY(float m_y)
{
	this->position.y += m_y;
	this->firingPosition.y += m_y;
}

bool Ship::isDead()
{
	return this->hp <= 0;
}

void Ship::applyChangeToSprite(cocos2d::Sprite* s)
{
	s->setPosition(this->position);
}

void Ship::IA(float delta)
{

}