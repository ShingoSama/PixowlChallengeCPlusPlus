#include "Bubble.h"
#include "Definitions.h"

USING_NS_CC;

Bubble::Bubble(cocos2d::Scene* layer, cocos2d::Vec2 posDest)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	
	bubble = Sprite::create(BUBBLESPRITE);
	Vec2 bubbleposition = Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
	
	bubble->setPosition(bubbleposition);
	bubble->setScale(0.2, 0.2);
	auto bubbleBody = PhysicsBody::createCircle(bubble->getContentSize().width/2);
	bubbleBody->setCollisionBitmask(BUBLE_COLLISION_BITMASK);
	bubbleBody->setDynamic(false);
	bubbleBody->setContactTestBitmask(true);
	bubble->setPhysicsBody(bubbleBody);
	soundEffect.preload(POPBUBBLE);

	Vec2 movedestination;

	if (posDest.x < bubbleposition.x)
	{
		movedestination.x = (bubbleposition.x - posDest.x) * -1;
	}
	else
	{
		movedestination.x = (posDest.x - bubbleposition.x);
	}
	if (posDest.y < bubbleposition.y)
	{
		movedestination.y = (bubbleposition.y - posDest.y) * -1;
	}
	else
	{
		movedestination.y = (posDest.y - bubbleposition.y);
	}
	bubbleBody->setVelocity(Vec2(movedestination.x*1.1, movedestination.y*1.1));

	layer->addChild(bubble, 3);
}

void Bubble::Destroy()
{
	PlaySoundEffect(POPBUBBLE);
}

void Bubble::PlaySoundEffect(std::string soundPath)
{
	soundEffect.play2d(soundPath);
}