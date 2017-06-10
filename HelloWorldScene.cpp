#include "HelloWorldScene.h"

#include <cmath>

#define VITESSESHIP 500
#define BULLETLIFESPAN 50
#define VITESSEBULLET 500
#define FIRERATE 5
#define LIMITE 20

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	keyboardHandler = KeyboardHandler();
	mouseHandler = MouseHandler();


    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 , origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...
	
	//BACKGROUND
	background = Sprite::create("SpaceBackground.png");
	background->setScaleX(visibleSize.width / background->getBoundingBox().size.width);
	background->setScaleY(visibleSize.height / background->getBoundingBox().size.height);
	background->setPosition(visibleSize.width/2, visibleSize.height/2);
	background->setRotation(0.f);

	//SHIP
	shipSprite = Sprite::create("Ship.png");
	shipSprite->setAnchorPoint(Vec2(0.5f, 0.f));
	shipSprite->setPosition(visibleSize.width/2, 0.f);
	shipSprite->setScale(0.1f);

	//Ship
	ennemie = Ship(200.f, 500.f, 500.f, 500.f, 480.f);
	ennemieSprite = Sprite::create("Ship.png");
	ennemieSprite->setAnchorPoint(Vec2(0.5f, 1.f));
	ennemieSprite->setFlippedY(true);
	ennemieSprite->setScale(0.2f);
	ennemie.applyChangeToSprite(ennemieSprite);

	//ADDS
	this->addChild(background);
	this->addChild(shipSprite, 42);
	this->addChild(ennemieSprite, 41);

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardHandler.getKeyboard(), this);
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseHandler.getMouse(), this);
	this->scheduleUpdate();

    
    
    return true;
}

void HelloWorld::update(float delta)
{
	Node::update(delta);
	timerBullet += delta;
	timerEnnemieBullet += delta;
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////           SHIP           ////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (keyboardHandler.isKeyPressed(EventKeyboard::KeyCode::KEY_LEFT_ARROW))
		shipSprite->setPosition(shipSprite->getPosition() + Vec2(-1.f, 0.f) * VITESSESHIP * delta);
	
	if (keyboardHandler.isKeyPressed(EventKeyboard::KeyCode::KEY_RIGHT_ARROW))
		shipSprite->setPosition(shipSprite->getPosition() + Vec2( 1.f, 0.f) * VITESSESHIP * delta);

	/*if (mouseHandler.isButtonPressed(0))
	{
		if (timerBullet > 1.f / FIRERATE)
		{
			timerBullet = fmod(timerBullet, 1.f / FIRERATE);

			auto *sprite = Sprite::create("bullet.png");
			sprite->setPosition(shipSprite->getPosition() + Vec2(0.f, shipSprite->getBoundingBox().size.height));
			this->addChild(sprite, 2);

			this.push_back(sprite);
		}
	}
	else
	{
		timerBullet = 1.f / FIRERATE;
	}*/

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////         Ennemies         ////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	if (keyboardHandler.isKeyPressed(EventKeyboard::KeyCode::KEY_A))
		ennemie.moveX(-1.f * VITESSESHIP * delta);

	if (keyboardHandler.isKeyPressed(EventKeyboard::KeyCode::KEY_D))
		ennemie.moveX(1.f * VITESSESHIP * delta);

	ennemie.applyChangeToSprite(ennemieSprite);

	if (mouseHandler.isButtonPressed(1))
	{
		if (timerEnnemieBullet > 1.f / FIRERATE/1000)
		{
			timerEnnemieBullet = fmod(timerShipBullet, 1.f / FIRERATE/1000);
			horloge += 1.f;
			
			Bullet b1 = ennemie.addBullet(Vec2(sin(horloge * 20), cos(horloge * 20)), 300, 100);
			Bullet b2 = ennemie.addBullet(Vec2(-sin(horloge * 20), -cos(horloge * 20)), 300, 100);

			auto *sprite = Sprite::create("Bullet.png");
			auto *sprite2 = Sprite::create("Bullet.png");

			sprite->setPosition(ennemie.getFiringPosition());
			sprite2->setPosition(ennemie.getFiringPosition());
			
			sprite->runAction(MoveBy::create(BULLETLIFESPAN, b1.getDirection() * b1.getVelocity() * BULLETLIFESPAN));
			sprite2->runAction(MoveBy::create(BULLETLIFESPAN, b2.getDirection() * b2.getVelocity() * BULLETLIFESPAN));

			this->addChild(sprite, 2);
			this->addChild(sprite2, 2);


			ennemieBulletsSprite.push_back(sprite);
			ennemieBulletsSprite.push_back(sprite2);

		}
	}
	else
	{
		timerEnnemieBullet = 1.f / FIRERATE;
	}




	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////         BULLETS          ////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		
	ennemie.updateBullets(delta);
	std::vector<int> deletedBullets = ennemie.deleteOutOfBoundsBullets(visibleSize.width, visibleSize.height);
	for (int i{ 0 }; i < (int)deletedBullets.size(); i++)
	{
		this->removeChild(ennemieBulletsSprite.at(deletedBullets.at(i)), true);
		ennemieBulletsSprite.erase(ShipBulletsSprite.begin() + deletedBullets.at(i));
	}


	/*for (int i{ 0 }; i < (int)Ship.getBullets().size(); i++)
	{
		float distance = abs(Ship.getBullet(i).getPosition().x - shipSprite->getPosition().x) + abs(Ship.getBullet(i).getPosition().y - shipSprite->getPosition().y);
		if (distance < LIMITE)
			cocos2d::experimental::AudioEngine::play2d("Fouet.mp3", false, 0.002f);
	}*/

}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
