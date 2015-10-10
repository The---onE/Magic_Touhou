#pragma once

#include "cocos2d.h"
#include "GameScene.h"
USING_NS_CC;

class TouchLayer : public Layer
{
public:
	CREATE_FUNC(TouchLayer);
	bool init();
	void onEnter();
	bool onTouchBegan(Touch *pTouch, Event *pEvent);
	void onTouchMoved(Touch *pTouch, Event *pEvent);
	void onTouchEnded(Touch *pTouch, Event *pEvent);

	Point offset;
	Size visibleSize;
	Sprite* player;
	//CCAction* run2p;
};

