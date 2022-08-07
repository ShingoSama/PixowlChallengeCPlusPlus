#include "GameScene.h"
#include <cocos/ui/UIButton.h>

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto spriteBacground = Sprite::create("Assets/Sprites/background.png");
    spriteBacground->setAnchorPoint(Vec2::ZERO);
    spriteBacground->setPosition(Vec2::ZERO);
    addChild(spriteBacground, 0);
    
    Vec2 centerPosition = Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
    
    goldFish = Sprite::create("Assets/Sprites/fish.png");
    goldFish->setPosition(centerPosition);
    goldFish->setScale(0.1, 0.1);
   
    //auto body = PhysicsBody::createCircle(goldFish->getContentSize().width / 2);
    //body->setContactTestBitmask(true);
    //body->setDynamic(true);
    //goldFish->setPhysicsBody(body);

    //AddBodyToFish(goldFish);
    addChild(goldFish, 1);
    this->schedule(CC_SCHEDULE_SELECTOR(GameScene::SpawnBadFish), 2);
    //this->schedule(CC_SCHEDULE_SELECTOR(GameScene::AddBadFish), 2);
    return true;
}

void GameScene::AddBadFish( float dt)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Sprite* badfish = nullptr;
    for (int i = 0; i < 3; i++)
    {
        badfish = Sprite::create("Assets/Sprites/badFish.png");
        badfish->setScale(0.1, 0.1);
        badfish->setPosition(CCRANDOM_0_1() * visibleSize.width, visibleSize.height);
        //AddBodyToFish(badfish);
        badFishs.pushBack(badfish);
        this->addChild(badfish, 1);
    }
}
void AddBodyToFish(cocos2d::Sprite* sprite)
{
    auto body = PhysicsBody::createCircle(sprite->getContentSize().width/2);
    body->setContactTestBitmask(true);
    body->setDynamic(true);
    sprite->setPhysicsBody(body);
}

void GameScene::SpawnBadFish(float dt)
{
    badFish.SpawnBadFish(this);
}