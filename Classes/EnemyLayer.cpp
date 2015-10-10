#include "EnemyLayer.h"

bool EnemyLayer::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	Enemy = Sprite::create();
	SpriteFrameCache *cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("sakuya.plist","sakuya.png");
	Animation *enemyAnimate = Animation::create();
	for (int i=0; i<17; i++)
	{
		char name[32];
		sprintf(name, "e1_%d.png", i);
		enemyAnimate->addSpriteFrame(cache->getSpriteFrameByName(name));
	}
	enemyAnimate->setDelayPerUnit(0.15f);
	Enemy->runAction(RepeatForever::create(Animate::create(enemyAnimate)));

	Enemy->setPosition(Point(origin.x+visibleSize.width*7/8, origin.y+visibleSize.height*3/6));
	Enemy->setFlippedX(true);
	Enemy->setScale(0.5f);
	this->addChild(Enemy);

	Health = Sprite::create("enemyhealth.png", Rect(0, 0, visibleSize.width/2, 25));
	Health->setAnchorPoint(Point(1, 1));
	Health->setPosition(Point(origin.x+visibleSize.width, origin.y+visibleSize.height));
	this->addChild(Health);

	return true;
}