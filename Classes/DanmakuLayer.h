#pragma once

#include "cocos2d.h"
USING_NS_CC;
class DanmakuLayer :public Layer
{
public:
	CREATE_FUNC(DanmakuLayer);
	bool init();
	bool P2P(Point Aim, Point Boss, int num, int angelDeg,int speed);

	Array* danmakuArray;
};

