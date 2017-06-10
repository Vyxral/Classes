#include "Bullet.h"


Bullet::Bullet()
{
	this->position = cocos2d::Vec2();
	this->direction = cocos2d::Vec2();
	this->velocity = 0.f;
	this->power = 0.f;
}

Bullet::Bullet(cocos2d::Vec2 p, cocos2d::Vec2 d, float m_v, float m_p)
{
	this->position = p;
	this->direction = d.getNormalized();
	this->velocity = m_v;
	this->power = m_p;
}

cocos2d::Vec2 Bullet::getPosition()
{
	return this->position;
}

cocos2d::Vec2 Bullet::getDirection()
{
	return this->direction;
}

float Bullet::getVelocity()
{
	return this->velocity;
}

float Bullet::getPower()
{
	return this->velocity;
}

void Bullet::update(float delta)
{
	this->position += this->direction*delta*this->velocity;
}