#ifndef _KEYBOARDHANDLER_H_
#define _KEYBOARDHANDLER_H_

#include <map>

#include "cocos2d.h"

class KeyboardHandler
{

	private : 
		cocos2d::EventListenerKeyboard* keyboard;
		static std::map<cocos2d::EventKeyboard::KeyCode, std::chrono::high_resolution_clock::time_point> keys;
		static std::vector<cocos2d::EventKeyboard::KeyCode> pressedKeyCollection;


	public :
		KeyboardHandler();

		//getters
		cocos2d::EventListenerKeyboard* getKeyboard();

		//methods
		bool isKeyPressed(cocos2d::EventKeyboard::KeyCode);
		double keyPressedTime(cocos2d::EventKeyboard::KeyCode);
		std::vector<cocos2d::EventKeyboard::KeyCode> pressedKeys();

};


#endif
