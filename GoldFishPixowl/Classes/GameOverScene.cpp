#include "GameOverScene.h"
#include <cocos/ui/UIButton.h>
#include "Definitions.h"
#include "MainMenuScene.h"

USING_NS_CC;

unsigned int score;

Scene* GameOverScene::createScene( unsigned int tempscore )
{
    score = tempscore;
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

    GetScreenDimensions();
    SetGameBackground();
    AddGameOverButton();
    
    highScoreLabel = Label::createWithTTF("2", FONTGAME, 35);
    highScoreLabel->setColor(Color3B::RED);

    UserDefault* def = UserDefault::getInstance();
    auto highScore = def->getIntegerForKey(HIGHSCORE, 0);

    if (score > highScore)
    {
        highScore = score;
        def->setIntegerForKey(HIGHSCORE, highScore);
        highScoreLabel->setString(HIGHSCORETEXT2 + std::to_string(highScore));
    }
    else
    {
        highScoreLabel->setString(HIGHSCORETEXT1 + std::to_string(highScore));
    }
    def->flush();

    highScoreLabel->setPosition(Vec2(centerPosition.x, centerPosition.y - 80));
    this->addChild(highScoreLabel, 10);

    scoreLabel = Label::createWithTTF("2", FONTGAME, 35);
    scoreLabel->setColor(Color3B::BLUE);
    scoreLabel->setString(SCORETEXT1 + std::to_string(score));
    scoreLabel->setPosition(Vec2(centerPosition.x, centerPosition.y - 40));
    this->addChild(scoreLabel, 10);
    
    return true;
}

void GameOverScene::GoToGameScene(cocos2d::Ref* sender)
{
    auto scene = MainMenuScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void GameOverScene::SetGameBackground()
{
    auto spriteBacground = Sprite::create(GAMEBACKGROUND);
    spriteBacground->setPosition(centerPosition);
    addChild(spriteBacground, 0);
}

void GameOverScene::GetScreenDimensions()
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    centerPosition = Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
}

void GameOverScene::AddGameOverButton()
{
    ui::Button* gameOverButton = ui::Button::create();

    gameOverButton->setTitleText("Game Over");
    gameOverButton->setColor(Color3B::RED);
    gameOverButton->setTitleFontSize(35);

    Vec2 buttonPosition = centerPosition;
    gameOverButton->setPosition(buttonPosition);

    addChild(gameOverButton, 1);

    gameOverButton->addTouchEventListener(CC_CALLBACK_1(GameOverScene::GoToGameScene, this));
}