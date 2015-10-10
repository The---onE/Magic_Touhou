#include "PlayerLayer.h"

bool PlayerLayer::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	Player = Sprite::create();
	SpriteFrameCache *cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("reimu.plist","reimu.png");
	Animation *playerAnimate = Animation::create();
	for (int i=0; i<10; i++)
	{
		char name[32];
		sprintf(name, "%d.png", i);
		playerAnimate->addSpriteFrame(cache->getSpriteFrameByName(name));
	}
	playerAnimate->setDelayPerUnit(0.15f);
	Player->runAction(RepeatForever::create(Animate::create(playerAnimate)));

	Player->setPosition(Point(origin.x+visibleSize.width*1/8,origin.y+visibleSize.height*3/6));
	Player->setScale(0.4f);
	this->addChild(Player);

	Health = Sprite::create("selfhealth.png", Rect(0, 0, visibleSize.width/2, 25));
	Health->setAnchorPoint(Point(0, 1));
	Health->setPosition(Point(origin.x, origin.y+visibleSize.height));
	this->addChild(Health);

	return true;
}
