#ifndef __BUBBLE_H__
#define __BUBBLE_H__

#include "cocos2d.h"
#include "AudioEngine.h"

class Bubble
{
public:
	Bubble(cocos2d::Scene* layer, cocos2d::Vec2 posDest);
	void Destroy();
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Sprite* bubble;
	cocos2d::AudioEngine soundEffect;
	void PlaySoundEffect(std::string soundPath);
};
#endif //__BUBBLE_H__