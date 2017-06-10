#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include <algorithm>
#include <vector>

#include "cocos2d.h"
#include "AudioEngine.h"

//System
#include "KeyboardHandler.h"
#include "MouseHandler.h"

//Game Objects
#include "Ship.h"
#include "Bullet.h"

class HelloWorld : public cocos2d::Layer
{
	private :

		//System
		KeyboardHandler keyboardHandler;
		MouseHandler mouseHandler;

		//Graphics
		cocos2d::Sprite* background;
		cocos2d::Sprite* shipSprite;

		Ship ennemie;
		cocos2d::Sprite* ennemieSprite;
		std::vector<cocos2d::Sprite*> ennemieBulletsSprite;
		float timerEnnemieBullet;
		float horloge;


	public:
		static cocos2d::Scene* createScene();

		virtual bool init();

		void update(float);
		// a selector callback
		void menuCloseCallback(cocos2d::Ref* pSender);
    
		// implement the "static create()" method manually
		CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
