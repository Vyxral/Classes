#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "cocos2d.h"
#include "SpriteObject.h"

class Character
{
	private :
		SpriteObject visual;
	
	public :
		//Constructors
		Character();
		Character(float, float);
		Character(float, float, std::string);
		
		//Getters
		cocos2d::Vec2 getCoordonates();

		//Setters
		void setCoordonates(float, float);

		
		
};

#endif