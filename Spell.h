#ifndef _SPELL_H_
#define _SPELL_H_

#include <ctime>

#include "Character.h"

class Spell
{
	private :
		Character *caster;
		
		//try smooth(Vec2 target, elapsedTime, responseTime)
		cocos2d::Vec2 coordonates;
		cocos2d::Vec2 direction;
		
		time_t castTime;
		double travelingDuration;
		double travelingSpeed;
		
		double damageValue;
		
		//*****Attributs*****//
		bool penetrative;
		double damageLoss;
		
		bool aoe;
		double radius;
		
		//bool spliting;
		//bool bouncing;
		
		//bool vampiric;
		//bool gravity;
		
		
		
		
	//public :
	
	
	
};

#endif