#include "BadFish.h"
#include "Definitions.h"

USING_NS_CC;

BadFish::BadFish()
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
}

void BadFish::SpawnBadFish(cocos2d::Scene* layer)
{
	CCLOG("spawn fish");

	auto badfish = Sprite::create("Assets/Sprites/badFish.png");

	//badfish->setScale(0.1, 0.1);
	//badfish->setPosition(CCRANDOM_0_1() * visibleSize.width, visibleSize.height);

	auto badfishbody = PhysicsBody::createCircle(badfish->getContentSize().width / 2);

	auto random = CCRANDOM_0_1();
//UPSPAWN 0.00
//RIGHTPAWN 0.25
//DOWNPAWN 0.50
//LEFTPAWN 0.75
	Vec2 upPosition = Vec2(visibleSize.width / 2, visibleSize.height);
	Vec2 rightPosition = Vec2(visibleSize.width, visibleSize.height / 2);
	Vec2 downPosition = Vec2(visibleSize.width / 2, 0);
	Vec2 leftPosition = Vec2(0, visibleSize.height / 2);
	if (random > UPSPAWN && random < RIGHTPAWN)
	{
		//UPSPAWN
		badfish->setPosition(upPosition);
	}
	if (random > RIGHTPAWN && random < DOWNPAWN)
	{
		//RIGHTPAWN
		badfish->setPosition(rightPosition);
	}
	if (random > DOWNPAWN && random < LEFTPAWN)
	{
		//DOWNPAWN
		badfish->setPosition(downPosition);
	}
	if (random > LEFTPAWN)
	{
		//LEFTPAWN
		badfish->setPosition(leftPosition);
	}
	badfish->setScale(0.1, 0.1);

	layer->addChild(badfish);

}
void onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{

}