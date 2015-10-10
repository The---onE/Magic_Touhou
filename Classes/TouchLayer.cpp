#include "TouchLayer.h"

bool TouchLayer::init()
{
	//run2p = NULL;
	visibleSize = Director::getInstance()->getVisibleSize();
	return true;
}

void TouchLayer::onEnter()
{
	CCLayer::onEnter();
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(TouchLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(TouchLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(TouchLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithFixedPriority(listener, 100);
}

bool TouchLayer::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	player = ((GameScene*)(this->getParent()))->player->Player;
	Point touchPoint = Director::getInstance()->convertToGL(pTouch->getLocationInView());
	offset = Point(touchPoint.x-player->getPositionX(), touchPoint.y-player->getPositionY());
	return true;
}

void TouchLayer::onTouchMoved(Touch *pTouch, Event *pEvent)
{
// 	if (run2p)
// 		player->stopAction(run2p);
// 	CCPoint aim = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
// 	CCActionInterval *run = CCMoveTo::create(aim.getDistance(player->getPosition()), aim);
// 	run2p = CCSpeed::create(run, 100);
// 	player->runAction(run2p);

	Point touchPoint = Director::getInstance()->convertToGL(pTouch->getLocationInView());
	Point position = Point(touchPoint.x-offset.x, touchPoint.y-offset.y);
	if (position.x < 0)
	{
		position.x = 0;
		offset.x = touchPoint.x;
	}
	if (position.y < 0)
	{
		position.y = 0;
		offset.y = touchPoint.y;
	}
	if (position.x > visibleSize.width)
	{
		position.x = visibleSize.width;
		offset.x = touchPoint.x - visibleSize.width;
	}
	if (position.y > visibleSize.height)
	{
		position.y = visibleSize.height;
		offset.y = touchPoint.y - visibleSize.height;
	}
	player->setPosition(position);
}

void TouchLayer::onTouchEnded(Touch *pTouch, Event *pEvent)
{

}