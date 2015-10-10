#pragma once

#include "cocos2d.h"
USING_NS_CC;

class EnemyLayer : public Layer
{
public:
	CREATE_FUNC(EnemyLayer);
	bool init();

	Sprite* Enemy;
	Sprite* Health;
};

