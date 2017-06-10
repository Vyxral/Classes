#include "KeyboardHandler.h"

KeyboardHandler::KeyboardHandler()
{

	keyboard = cocos2d::EventListenerKeyboard::create();
	cocos2d::Director::getInstance()->getOpenGLView()->setIMEKeyboardState(true);
	pressedKeyCollection.clear();

	keyboard->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		if (keys.find(keyCode) == keys.end())
		{
			keys[keyCode] = std::chrono::high_resolution_clock::now();
			pressedKeyCollection.push_back(keyCode);
		}
	};
	keyboard->onKeyReleased = [=](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		keys.erase(keyCode);
		pressedKeyCollection.erase(std::remove(pressedKeyCollection.begin(), pressedKeyCollection.end(), keyCode), pressedKeyCollection.end());
	};


}

cocos2d::EventListenerKeyboard* KeyboardHandler::getKeyboard()
{
	return keyboard;
}


bool KeyboardHandler::isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{
	return keys.find(keyCode) != keys.end();
}

double KeyboardHandler::keyPressedTime(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (keys.find(keyCode) != keys.end())
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - keys[keyCode]).count();
}

std::vector<cocos2d::EventKeyboard::KeyCode> KeyboardHandler::pressedKeys()
{
	return pressedKeyCollection;
}

std::map<cocos2d::EventKeyboard::KeyCode, std::chrono::high_resolution_clock::time_point> KeyboardHandler::keys;
std::vector<cocos2d::EventKeyboard::KeyCode> KeyboardHandler::pressedKeyCollection;