#include "DanmakuLayer.h"

bool DanmakuLayer::init()
{
	danmakuArray = Array::create();
	CC_SAFE_RETAIN(danmakuArray);

	return true;
}

bool DanmakuLayer::P2P(Point Aim, Point Boss, int num, int angelDeg, int speed)
{
	Point Temp;
	float angelRad = (float)angelDeg/180*3.14 / num;
	int d = Aim.getDistance(Boss);
	float halfangle = angelRad / 2;
 	if (num%2 == 1)
 	{
 		halfangle = 0;
 		Sprite *Bullet = Sprite::create("bullet.png");
 		danmakuArray->addObject(Bullet);
 		Bullet->setPosition(Boss);
 		this->addChild(Bullet, 1);

		Point Temp = Point(Aim.x - Boss.x, Aim.y - Boss.y);
		ActionInterval* run = MoveBy::create(d, Temp);
		RepeatForever* runf = RepeatForever::create(run);
		Speed* runs = Speed::create(runf, speed*10);
		Bullet->runAction(runs);
 	}
 	for (int i=1; i<=(num/2); i++)
 	{
 		Sprite *Bullet = Sprite::create("bullet.png");
 		danmakuArray->addObject(Bullet);
 		Bullet->setPosition(Boss);
 		this->addChild(Bullet, 1);
 
 		float angel = angelRad * i -halfangle;
 		int x = (Aim.x - Boss.x)*cos(angel) - (Aim.y - Boss.y)*sin(angel);
 		int y = (Aim.y - Boss.y)*cos(angel) + (Aim.x - Boss.x)*sin(angel);
 
 		Temp = Point(x, y);
		ActionInterval* run = MoveBy::create(d, Temp);
		RepeatForever* runf = RepeatForever::create(run);
		Speed* runs = CCSpeed::create(runf, speed*10);
		Bullet->runAction(runs);
 	}
 	for (int i=1; i<=(num/2); i++)
 	{
 		Sprite *Bullet = Sprite::create("bullet.png");
 		danmakuArray->addObject(Bullet);
 		Bullet->setPosition(Boss);
 		this->addChild(Bullet, 1);
 
 		float angel = -angelRad * i +halfangle;
 		int x = (Aim.x - Boss.x)*cos(angel) - (Aim.y - Boss.y)*sin(angel);
 		int y = (Aim.y - Boss.y)*cos(angel) + (Aim.x - Boss.x)*sin(angel);
 
 		Temp = Point(x, y);
 		ActionInterval* run = MoveBy::create(d, Temp);
 		RepeatForever* runf = RepeatForever::create(run);
		Speed* runs = CCSpeed::create(runf, speed*10);
 		Bullet->runAction(runs);
 	}

	return true;
}
