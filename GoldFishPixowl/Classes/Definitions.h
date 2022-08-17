#pragma once

#ifndef __DEFINITIONS_SCENE_H__
#define __DEFINITIONS_SCENE_H__

#define DISPLAY_TIME_PIXOWLGAMESCENE 2
#define TRANSITION_TIME 0.5

#define UPSPAWN 0.00
#define RIGHTPAWN 0.25
#define DOWNPAWN 0.50
#define LEFTPAWN 0.75

#define GOLDFISH_COLLISION_BITMASK 1
#define BADFISH_COLLISION_BITMASK 2
#define BUBLE_COLLISION_BITMASK 3

#define FONTGAME "fonts/Marker Felt.ttf"

//Text
#define STARTTEXT "Start"
#define GAMENAME "Gold Fish GAME"
#define HIGHSCORE "HIGHSCORE"
#define HIGHSCORETEXT1 "HIGHSCORE: "
#define HIGHSCORETEXT2 "Your new HIGSCORE score is: "
#define SCORETEXT1 "Your score is: "

//Audio files
#define GAMEMUSIC "Assets/Audio/Jaws.mp3"
#define POPBUBBLE "Assets/Audio/PopBubble.mp3"
#define SHOOTBUBBLE "Assets/Audio/Shoot.mp3"
#define PLAYERDEAD "Assets/Audio/Dead.mp3"

//Sprites files
#define GAMEBACKGROUND "Assets/Sprites/background.png"
#define GOLDFISHSPRITE1 "Assets/Sprites/fish.png"
#define GOLDFISHSPRITE2 "Assets/Sprites/fishBubble.png"
#define BUBBLESPRITE "Assets/Sprites/bubble.png"
#define BADFISHSPRITE "Assets/Sprites/badFish.png"
#endif