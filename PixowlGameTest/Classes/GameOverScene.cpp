#include "GameOverScene.h"
#include <cocos/ui/UIButton.h>

USING_NS_CC;

Scene* GameOverScene::createScene()
{
    return GameOverScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    ui::Button* startButton = ui::Button::create();
    startButton->setTitleText("Start");

    Vec2 buttonPosition = Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
    startButton->setPosition(buttonPosition);

    addChild(startButton, 1);

    auto spriteBacground = Sprite::create("Assets/Sprites/background.png");
    spriteBacground->setAnchorPoint(Vec2::ZERO);
    spriteBacground->setPosition(Vec2::ZERO);
    addChild(spriteBacground, 0);

    return true;
}