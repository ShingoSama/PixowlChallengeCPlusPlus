#include "MainMenuScene.h"
#include "GameScene.h"
#include "Definitions.h"
#include <cocos/ui/UIButton.h>

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    return MainMenuScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //Vec2 position = Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);

    //auto playItem = MenuItemImage::create("Assets/Sprites/menuBackground.png", "Assets/Sprites/menuBackground.png", CC_CALLBACK_1(MainMenuScene::GoToGameScene, this) );
    //playItem->setPosition(position);

    //auto menu = Menu::create(playItem, NULL);

    //menu->setPosition(Point::ZERO);

    //this->addChild(menu);
    
    //Background
    auto spriteBacground = Sprite::create("Assets/Sprites/background.png");
    spriteBacground->setAnchorPoint(Vec2::ZERO);
    spriteBacground->setPosition(Vec2::ZERO);
    addChild(spriteBacground, 0);
    //Button
    ui::Button* startButton = ui::Button::create();
    startButton->setTitleText("Start");

    Vec2 buttonPosition = Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
    startButton->setPosition(buttonPosition);

    addChild(startButton, 1);
    startButton->addTouchEventListener(CC_CALLBACK_1(MainMenuScene::GoToGameScene, this));

    return true;
}

void MainMenuScene::GoToGameScene(cocos2d::Ref* sender)
{
    auto scene = GameScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}