#pragma once
#ifndef __GAMESCENE_SCENE_H__
#define __GAMESCENE_SCENE_H__

#include "cocos2d.h"
#include "BadFish.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

private: 
    cocos2d::Sprite* goldFish;
    cocos2d::Vector<cocos2d::Sprite*> badFishs;
    void AddBadFish( float dt);
    void RotateGoldFish();
    void AddBodyToFish(cocos2d::Sprite* sprite);

    void SpawnBadFish(float dt);

    BadFish badFish;


};

#endif