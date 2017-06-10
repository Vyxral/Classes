#ifndef _MOUSEHANDLER_H_
#define _MOUSEHANDLER_H_

#include "cocos2d.h"

class MouseHandler
{
	private :
		cocos2d::EventListenerMouse* mouse;
		static std::vector<int> buttonPressedCollection;
		static cocos2d::Vec2 position;
		

	public :

		MouseHandler();

		//Getters
		cocos2d::EventListenerMouse* getMouse();
		cocos2d::Vec2 getPosition();

		//Method
		std::vector<int> getPressedButtons();
		bool isButtonPressed(int);

};


#endif