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
	goldfish = Sprite::create(GOLDFISHSPRITE2);
	goldfish->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	goldfish->setScale(0.1, 0.1);
	layer->addChild(goldfish, 2);
}

void GoldFish::Dead()
{
	PlaySoundEffect(PLAYERDEAD);
}

void GoldFish::PlaySoundEffect(std::string soundPath)
{
	soundEffect.play2d(soundPath);
}