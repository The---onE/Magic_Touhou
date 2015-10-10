#pragma once

#include "cocos2d.h"
USING_NS_CC;

class PlayerLayer : public Layer
{
public:
	CREATE_FUNC(PlayerLayer);
	bool init();

	Sprite* Player;
	Sprite* Health;
};

