#ifndef __BADFISH_H__
#define __BADFISH_H__

#include "cocos2d.h"

class BadFish
{
public:
	BadFish();
	void SpawnBadFish(cocos2d::Scene* layer);

private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	void onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
};
#endif //__BADFISH_H__