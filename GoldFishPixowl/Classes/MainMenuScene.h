#ifndef __MAINMENUSCENE_SCENE_H__
#define __MAINMENUSCENE_SCENE_H__

#include "cocos2d.h"
#include <cocos/ui/UIButton.h>
#include "AudioEngine.h"

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
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::Vec2 centerPosition;
    cocos2d::ui::Button* startButton;
    cocos2d::Label* gameLabel;
    cocos2d::Label* highScoreLabel;
    cocos2d::AudioEngine audiomenu;
    void GoToGameScene( cocos2d::Ref *sender);
    void SetGameBackground();
    void GetScreenDimensions();
    void SetButtonStart();
    void AddGameMusic();
    void AddGameLabel();
    void AddHighScoreLabel();
    int GetHighScore();
};

#endif