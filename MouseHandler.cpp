#include "MouseHandler.h"

MouseHandler::MouseHandler()
{
	mouse = cocos2d::EventListenerMouse::create();
	mouse->onMouseDown = [=](cocos2d::Event* event)
	{
		try
		{
			cocos2d::EventMouse* mouseEvent = dynamic_cast<cocos2d::EventMouse*>(event);
			buttonPressedCollection.push_back(mouseEvent->getMouseButton());
		}
		catch (std::bad_cast& e)
		{
			// Not sure what kind of event you passed us cocos, but it was the wrong one
			return;
		}
	};

	mouse->onMouseMove = [=](cocos2d::Event* event)
	{
		try
		{
			cocos2d::EventMouse* mouseEvent = dynamic_cast<cocos2d::EventMouse*>(event);
			position = cocos2d::Vec2(mouseEvent->getCursorX(), mouseEvent->getCursorY());
		}
		catch (std::bad_cast& e)
		{
			// Not sure what kind of event you passed us cocos, but it was the wrong one

		}
	};

	mouse->onMouseUp = [=](cocos2d::Event* event) {
		cocos2d::EventMouse* mouseEvent = dynamic_cast<cocos2d::EventMouse*>(event);
		buttonPressedCollection.erase(std::remove(buttonPressedCollection.begin(), buttonPressedCollection.end(), mouseEvent->getMouseButton()), buttonPressedCollection.end());
	};
}

cocos2d::EventListenerMouse* MouseHandler::getMouse()
{
	return mouse;
}

cocos2d::Vec2 MouseHandler::getPosition()
{
	return position;
}

std::vector<int> MouseHandler::getPressedButtons()
{
	return buttonPressedCollection;
}

bool MouseHandler::isButtonPressed(int b)
{
	std::vector<int>::iterator it;
	it = std::find(buttonPressedCollection.begin(), buttonPressedCollection.end(), b);
	return it != buttonPressedCollection.end();
}

std::vector<int> MouseHandler::buttonPressedCollection;
cocos2d::Vec2 MouseHandler::position;