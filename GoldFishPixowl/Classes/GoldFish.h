#ifndef __GOLDFISH_H__
#define __GOLDFISH_H__

#include "cocos2d.h"
#include "AudioEngine.h"

class GoldFish
{
public:
	GoldFish(cocos2d::Scene* layer);
	void Shoot();
	void Dead();
	void CloseMouth(cocos2d::Scene* layer);
	void Rotate(cocos2d::Vec2 posDes);
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Sprite* goldfish;
	cocos2d::AudioEngine soundEffect;
	void PlaySoundEffect(std::string soundPath);
};
#endif //__GOLDFISH_H__