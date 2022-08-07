#ifndef __MAINMENUSCENE_SCENE_H__
#define __MAINMENUSCENE_SCENE_H__

#include "cocos2d.h"
#include <cocos/ui/UIButton.h>

class MainMenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(MainMenuScene);
private:
    void GoToGameScene( cocos2d::Ref *sender);
};

#endif