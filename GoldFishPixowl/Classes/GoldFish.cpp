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
void GoldFish::Shoot()
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
	//obtengo la posicion del pez dorado para calcular la diferencia con el click
	Vec2 goldfisPosition = goldfish->getPosition();
	// obtengo la diferencia
	Vec2 direction = posDest - goldfisPosition;
	//la paso a positivo para calcular la tangente
	Vec2 positiveDirection = direction;
	if (positiveDirection.y < 0)
	{
		positiveDirection.y *= -1;
	}
	if (positiveDirection.x < 0)
	{
		positiveDirection.x *= -1;
	}
	//Calculo tangente a la -1 y lo convierto a grados
	float tan_a = (positiveDirection.y / positiveDirection.x);
	float atan_a = (atan(tan_a) * 180) / M_PI;

	float rotation = goldfish->getRotation();
	int grad = 0;
	if (direction.y > 0 && direction.x > 0)
	{
		grad = 90 - atan_a;
		rotation = grad - rotation;
	}
	if (direction.y > 0 && direction.x < 0)
	{
		grad = (90 - atan_a) * -1;
		rotation = grad - rotation;
	}
	if (direction.y < 0 && direction.x > 0)
	{
		grad = (90 + atan_a);
		rotation = grad - rotation;
	}
	if (direction.y < 0 && direction.x < 0)
	{
		grad = (90 + atan_a) * -1;
		rotation = grad - rotation;
	}
	//agrego la accion de rotar + los grados de rotacion calculados
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