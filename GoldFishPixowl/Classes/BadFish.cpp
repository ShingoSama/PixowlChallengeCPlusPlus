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
	auto badfish = Sprite::create(BADFISHSPRITE);

	auto badfishbody = PhysicsBody::createCircle(badfish->getContentSize().width / 2);
	badfishbody->setCollisionBitmask(BADFISH_COLLISION_BITMASK);
	badfishbody->setDynamic(false);
	badfishbody->setContactTestBitmask(true);
	badfish->setPhysicsBody(badfishbody);

	//UPSPAWN 0.00
	//RIGHTPAWN 0.25
	//DOWNPAWN 0.50
	//LEFTPAWN 0.75

	auto randompos = CCRANDOM_0_1();

	// Position of AXIS x or y

	auto randompos2 = CCRANDOM_0_1();
	float pospercentage;
	
	if (randompos2 > UPSPAWN && randompos2 < RIGHTPAWN)
	{
		pospercentage = 0.25;
	}
	if (randompos2 > RIGHTPAWN && randompos2 < DOWNPAWN)
	{
		pospercentage = 0.50;
	}
	if (randompos2 > DOWNPAWN && randompos2 < LEFTPAWN)
	{
		pospercentage = 0.75;
	}
	if (randompos2 > LEFTPAWN)
	{
		pospercentage = 1;
	}
	Vec2 badfishposition;
	Vec2 movingPosition;
	int direction;

	if (randompos > UPSPAWN && randompos < RIGHTPAWN)
	{
		//UPSPAWN

		direction = (visibleSize.width + origin.x * 2)/2 - (visibleSize.width + origin.x) * pospercentage;
		badfishposition = Vec2((visibleSize.width + origin.x) * pospercentage, visibleSize.height);
		movingPosition = Vec2(direction, (visibleSize.height / 2 + origin.y) * -1);
	}
	if (randompos > RIGHTPAWN && randompos < DOWNPAWN)
	{
		//RIGHTPAWN
		direction = (visibleSize.height) / 2 - (visibleSize.height) * pospercentage;
		badfishposition = Vec2(visibleSize.width, visibleSize.height * pospercentage);
		movingPosition = Vec2((visibleSize.width / 2 - origin.x) * -1, direction);
	}
	if (randompos > DOWNPAWN && randompos < LEFTPAWN)
	{
		//DOWNPAWN
		direction = (visibleSize.width + origin.x * 2) / 2 - (visibleSize.width + origin.x) * pospercentage;
		badfishposition = Vec2((visibleSize.width + origin.x) * pospercentage, 0);
		movingPosition = Vec2(direction, (visibleSize.height / 2 + origin.y));
	}
	if (randompos > LEFTPAWN)
	{
		//LEFTPAWN
		direction = (visibleSize.height) / 2 - (visibleSize.height) * pospercentage;
		badfishposition = Vec2(0, visibleSize.height * pospercentage);
		movingPosition = Vec2((visibleSize.width / 2 + origin.x), direction);
	}
	badfish->setPosition(badfishposition);
	badfish->setScale(0.1, 0.1);



	auto badfishAction = MoveBy::create(5, movingPosition);

	badfish->runAction(badfishAction);

	layer->addChild(badfish);

}