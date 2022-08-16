#include "GameScene.h"
#include <cocos/ui/UIButton.h>
#include "GameOverScene.h"
#include "Definitions.h"
#include "AudioEngine.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object 
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    // 
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    layer->setPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer);

    return scene;
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

    //Get screen dimension to set the sprites
    GetScreenDimensions();

    //Set Background sprite
    SetGameBackground();
    
    spawnTimes = 1;
    //Spawn enemies by 2 secs
    this->schedule(CC_SCHEDULE_SELECTOR(GameScene::SpawnBadFish), 2);

    //Instance gold fish (player)
    goldFish = new GoldFish(this);
    score = 0;
    //Add listener to collitions
    AddContactListener();

    //Add touch event listener
    AddTouchListener();
    
    //Add score label to screen
    AddGameScoreLabel();

    return true;
}

void GameScene::SpawnBadFish(float dt)
{
    for (int i = 0; i < spawnTimes; i++)
    {
        badFish.SpawnBadFish(this);
    }
}

bool GameScene::onContactBegin(cocos2d::PhysicsContact& contact)
{
    PhysicsBody* a = contact.getShapeA()->getBody();
    PhysicsBody* b = contact.getShapeB()->getBody();
    if (((3 == a->getCollisionBitmask()) && (2 == b->getCollisionBitmask())) ||
        ((2 == a->getCollisionBitmask()) && (3 == b->getCollisionBitmask())))
    {
        score += 1;
        if ((score % 4) == 0)
        {
            spawnTimes += 1;
        }
        scoreLabel->setString(std::to_string(score));
        bubble->Destroy();
        if (a->getNode() != NULL)
        {
            a->getNode()->removeFromParent();
        }
        if (b->getNode() != NULL)
        {
            b->getNode()->removeFromParent();
        }
    }
    if (((1 == a->getCollisionBitmask()) && (2 == b->getCollisionBitmask())) || 
        ((2 == a->getCollisionBitmask()) && (1 == b->getCollisionBitmask())))
    {
        goldFish->Dead();
        auto scene = GameOverScene::createScene();
        Director::getInstance()->replaceScene(scene);
    }
    return true;
}

bool GameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    Vec2 posDest = Vec2(touch->getLocation().x, touch->getLocation().y);
    
    if (true)
    {
        goldFish->Shoot(this);
        bubble = new Bubble(this, posDest);
    }
    return true;
}

void GameScene::AddContactListener()
{
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}

void GameScene::AddTouchListener()
{
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void GameScene::GetScreenDimensions()
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    centerPosition = Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
}

void GameScene::SetGameBackground()
{
    auto spriteBacground = Sprite::create(GAMEBACKGROUND);
    spriteBacground->setPosition(centerPosition);
    addChild(spriteBacground, 0);
}

void GameScene::AddGameScoreLabel()
{
    scoreLabel = Label::createWithTTF("2", "fonts/Marker Felt.ttf", 15);
    scoreLabel->setColor(Color3B::BLUE);
    scoreLabel->setString("0");
    Vec2 scorePosition = Vec2(centerPosition.x, visibleSize.height - 20);
    scoreLabel->setPosition(scorePosition);
    this->addChild(scoreLabel, 10);
}