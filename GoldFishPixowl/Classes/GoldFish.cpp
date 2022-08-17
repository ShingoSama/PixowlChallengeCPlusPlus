#include "GoldFish.h"
#include "Definitions.h"

USING_NS_CC;

GoldFish::GoldFish(cocos2d::Scene * layer)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	goldfish = Sprite::create(GOLDFISHSPRITE1);
	
	goldfish->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	goldfish->setScale(0.1, 0.1);
	auto goldfishBody = PhysicsBody::createCircle(goldfish->getContentSize().width/2);
	goldfishBody->setCollisionBitmask(GOLDFISH_COLLISION_BITMASK);
	goldfishBody->setDynamic(false);
	goldfishBody->setContactTestBitmask(true);
	goldfish->setPhysicsBody(goldfishBody);
	soundEffect.preload(SHOOTBUBBLE);
	soundEffect.preload(PLAYERDEAD);
	layer->addChild(goldfish, 2);
}
void GoldFish::Shoot(cocos2d::Scene* layer)
{
	PlaySoundEffect(SHOOTBUBBLE);
	goldfish->setTexture(GOLDFISHSPRITE2);;
}

void GoldFish::Dead()
{
	PlaySoundEffect(PLAYERDEAD);
}

void GoldFish::Rotate(Vec2 posDest)
{
	Vec2 goldfisPosition = goldfish->getPosition();
	Vec2 dirtection = posDest - goldfisPosition;
	Vec2 positiveDirection = dirtection;
	if (positiveDirection.y < 0)
	{
		positiveDirection.y = dirtection.y * -1;
	}
	if (positiveDirection.x < 0)
	{
		positiveDirection.x = dirtection.x * -1;
	}
	float tan_a = (positiveDirection.y / positiveDirection.x);
	float atan_a = (atan(tan_a) * 180) / M_PI;

	float rotation = goldfish->getRotation();
	int grad = 0;
	if (dirtection.y > 0 && dirtection.x > 0)
	{
		grad = 90 - atan_a;
		rotation = grad - rotation;
	}
	if (dirtection.y > 0 && dirtection.x < 0)
	{
		grad = (90 - atan_a) * -1;
		rotation = grad - rotation;
	}
	if (dirtection.y < 0 && dirtection.x > 0)
	{
		grad = (90 + atan_a);
		rotation = grad - rotation;
	}
	if (dirtection.y < 0 && dirtection.x < 0)
	{
		grad = (90 + atan_a) * -1;
		rotation = grad - rotation;
	}
	auto action = RotateBy::create(0, rotation);
	goldfish->runAction(action);
}

void GoldFish::PlaySoundEffect(std::string soundPath)
{
	soundEffect.play2d(soundPath);
}

void GoldFish::CloseMouth(cocos2d::Scene* layer)
{
	goldfish->setTexture(GOLDFISHSPRITE1);
}