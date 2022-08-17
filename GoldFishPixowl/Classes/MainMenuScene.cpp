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

    //Get screen dimension to set the sprites
    GetScreenDimensions();

    //Add game music with loop (if is not running)
    if (!(audiomenu.isLoop(0)))
    {
        AddGameMusic();
    }

    //Set Background sprite
    SetGameBackground();
    
    //Button Start
    SetButtonStart();

    //Add listener to start button
    startButton->addTouchEventListener(CC_CALLBACK_1(MainMenuScene::GoToGameScene, this));

    //Add the name of the game
    AddGameLabel();

    //Add high score label
    AddHighScoreLabel();

    return true;
}

void MainMenuScene::GoToGameScene(cocos2d::Ref* sender)
{
    auto scene = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void MainMenuScene::SetGameBackground()
{
    auto spriteBacground = Sprite::create(GAMEBACKGROUND);
    spriteBacground->setPosition(centerPosition);
    addChild(spriteBacground, 0);
}

void MainMenuScene::GetScreenDimensions()
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    centerPosition = Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
}

void MainMenuScene::SetButtonStart()
{
    startButton = ui::Button::create();
    startButton->setTitleText(STARTTEXT);
    startButton->setColor(Color3B::WHITE);
    startButton->setTitleFontSize(25);
    Vec2 buttonPosition = Vec2(centerPosition);
    startButton->setPosition(buttonPosition);
    addChild(startButton, 1);
}

void MainMenuScene::AddGameMusic()
{
    audiomenu.preload(GAMEMUSIC);
    audiomenu.play2d(GAMEMUSIC, true, 0.05);
}

void MainMenuScene::AddGameLabel()
{
    gameLabel = Label::createWithTTF("2", FONTGAME, 40);
    gameLabel->setColor(Color3B::BLUE);
    gameLabel->setString(GAMENAME);
    Vec2 scorePosition = Vec2(centerPosition.x, visibleSize.height - 50);
    gameLabel->setPosition(scorePosition);
    this->addChild(gameLabel, 10);
}

void MainMenuScene::AddHighScoreLabel()
{
    highScoreLabel = Label::createWithTTF("2", FONTGAME, 25);
    highScoreLabel->setColor(Color3B::RED);
    highScoreLabel->setString(HIGHSCORETEXT1 + std::to_string(GetHighScore()));
    Vec2 scorePosition = Vec2(centerPosition.x, centerPosition.y - 200);
    highScoreLabel->setPosition(scorePosition);
    this->addChild(highScoreLabel, 10);
}

int MainMenuScene::GetHighScore()
{
    UserDefault* def = UserDefault::getInstance();
    auto highScore = def->getIntegerForKey(HIGHSCORE, 0);
    def->flush();
    return highScore;
}