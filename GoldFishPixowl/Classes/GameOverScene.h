#pragma once
#ifndef __GAMEOVERSCENE_SCENE_H__
#define __GAMEOVERSCENE_SCENE_H__

#include "cocos2d.h"
#include <cocos/ui/UIButton.h>

class GameOverScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::Vec2 centerPosition;
    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(GameOverScene);
private:
    void GoToGameScene(cocos2d::Ref* sender);
    void SetGameBackground();
    void GetScreenDimensions();
    void AddGameOverButton();
};

#endif