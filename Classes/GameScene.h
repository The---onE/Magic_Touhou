#pragma once

#include "cocos2d.h"
#include "HelloWorld.h"
#include "TouchLayer.h"
#include "DanmakuLayer.h"
#include "PlayerLayer.h"
#include "EnemyLayer.h"
USING_NS_CC;
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

class GameScene : public Scene
{
public:
	CREATE_FUNC(GameScene);
	bool init();
	void GameLogic();
	void Stage1(float dt);
	void Stage2(float dt);
	void Stage2_2(float dt);
	void Stage3(float dt);
	void Stage4(float dt);
	void Stage5(float dt);
	void Stage6(float dt);
	void update(float dt);

	Size visibleSize;
	Point origin;
	bool flag;

	HelloWorld* bg;
	DanmakuLayer* danmaku;
	PlayerLayer* player;
	EnemyLayer* enemy;

};
