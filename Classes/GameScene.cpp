#include "GameScene.h"

bool GameScene::init()
{
	Scene::init();

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("bgm.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("hurt.wav");
	SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm.mp3");

	bg = HelloWorld::create();
	this->addChild(bg);
	TouchLayer* touch = TouchLayer::create();
	this->addChild(touch);
	danmaku = DanmakuLayer::create();
	this->addChild(danmaku);
	player = PlayerLayer::create();
	this->addChild(player);
	enemy = EnemyLayer::create();
	this->addChild(enemy);

	flag = false;

	this->scheduleUpdate();
	this->GameLogic();

	return true;
}

void GameScene::GameLogic()
{
	this->schedule(schedule_selector(GameScene::Stage1), 1, 9, 0);
	this->schedule(schedule_selector(GameScene::Stage2), 0.9f, 19, 10);
	this->schedule(schedule_selector(GameScene::Stage3), 0.8f, 19, 28);
	this->schedule(schedule_selector(GameScene::Stage4), 0.7f, 19, 44);
	this->schedule(schedule_selector(GameScene::Stage5), 0.6f, 19, 58);
	this->schedule(schedule_selector(GameScene::Stage6), 0.5f, UINT_MAX-1, 70);
}
void GameScene::Stage1(float dt)
{
	danmaku->P2P(player->Player->getPosition(), enemy->Enemy->getPosition(), 7, 60, 23);
}
void GameScene::Stage2(float dt)
{
	danmaku->P2P(player->Player->getPosition(), enemy->Enemy->getPosition(), 15, 90, 25);
	this->scheduleOnce(schedule_selector(GameScene::Stage2_2),0.45f);
}
void GameScene::Stage2_2(float dt)
{
	danmaku->P2P(player->Player->getPosition(), enemy->Enemy->getPosition(), 14, 90, 25);
}
void GameScene::Stage3(float dt)
{
	danmaku->P2P(player->Player->getPosition(), enemy->Enemy->getPosition(), 25, 120, 30);
}
void GameScene::Stage4(float dt)
{
	danmaku->P2P(player->Player->getPosition(), enemy->Enemy->getPosition(), 29, 120, 35);
}
void GameScene::Stage5(float dt)
{
	danmaku->P2P(player->Player->getPosition(), enemy->Enemy->getPosition(), 33, 120, 40);
}
void GameScene::Stage6(float dt)
{
	danmaku->P2P(player->Player->getPosition(), enemy->Enemy->getPosition(), 45, 150, 45);
}


void GameScene::update(float dt)
{
	float _rest = enemy->Health->getScaleX()-0.00021f;
	if (_rest<0 && flag==false)
	{
		Sprite* Victory = Sprite::create("victory.png");
		Victory->setPosition(Point(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
		addChild(Victory, 900);
		flag = true;
	}
	else
	{
		enemy->Health->setScaleX(_rest);
	}

	Point playerPosition = player->Player->getPosition();
	for (int i=danmaku->danmakuArray->count()-1; i>=0; --i)
	{
		Sprite* bullet = (Sprite*)danmaku->danmakuArray->getObjectAtIndex(i);
		Point position = bullet->getPosition();
		if (position.x<0 || position.y<0 || position.x>visibleSize.width || position.y>visibleSize.height)
		{
			danmaku->danmakuArray->removeObject(bullet);
			danmaku->removeChild(bullet);
		}

		if (position.getDistance(playerPosition) < 12)
		{
			danmaku->danmakuArray->removeObject(bullet);
			danmaku->removeChild(bullet);
			float rest = player->Health->getScaleX()-0.0625f;
			SimpleAudioEngine::getInstance()->playEffect("hurt.wav");
			if (rest<0 && flag==false)
			{
				Sprite* GameOver = Sprite::create("gameover.png");
				GameOver->setPosition(Point(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
				addChild(GameOver, 1000);
				SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
				flag = true;
			}
			else
			{
				player->Health->setScaleX(rest);
			}
		}
	}
}