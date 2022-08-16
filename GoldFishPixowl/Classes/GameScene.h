#pragma once
#ifndef __GAMESCENE_SCENE_H__
#define __GAMESCENE_SCENE_H__

#include "cocos2d.h"
#include "BadFish.h"
#include "GoldFish.h"
#include "Bubble.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::Vec2 centerPosition;
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

private: 
    BadFish badFish;
    GoldFish* goldFish;
    Bubble* bubble;
    int score;
    float spawnTimes;
    cocos2d::Label* scoreLabel;
    void setPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; }
    cocos2d::PhysicsWorld* sceneWorld;
    void SpawnBadFish(float dt);
    bool onContactBegin(cocos2d::PhysicsContact &contact);
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void GetScreenDimensions();
    void SetGameBackground();
    void AddContactListener();
    void AddTouchListener();
    void AddGameScoreLabel();
};

#endif