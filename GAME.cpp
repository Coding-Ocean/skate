#include"..\libOne\inc\libOne.h"
#include "GAME.h"

GAME::GAME()
{
}

void GAME::run()
{
    window(640, 433);

    int imgs = loadImage("assets/skate.png");
    Building.cutImg(imgs);

    GameState = TITLE;
    initDeltaTime();
    while (notQuit)
    {
        setDeltaTime();
        if      (GameState == TITLE ) { Title(); }
        else if (GameState == PLAY  ) { Play(); }
        else if (GameState == RESULT) { Result(); }
    }
}

void GAME::Init()
{
}

void GAME::Title()
{
    //draw
    clear();
    fill(255, 255, 255);
    text("スケボー", 100, 100);
    text("Push \"Enter\" to start.", 200, 300);

    //next state
    if (isTrigger(KEY_ENTER)) {
        GameState = PLAY;
        Init();
    }
}

void GAME::Play()
{
    //move
    Building.move();

    //draw
    clear();
    fill(64, 128, 255);
    rect(0, 0, width, height);
    Building.draw();

    //next state
    if (isTrigger(KEY_ENTER)) {
        GameState = RESULT;
    }
}

void GAME::Result()
{
    //draw
    clear();
    fill(64, 128, 255);
    rect(0, 0, width, height);
    fill(255, 255, 255);
    text("ゲームオーバー", 100, 100);
    text("Push \"Enter\" to restart.", 200, 280);

    //next state
    if (isTrigger(KEY_ENTER)) {
        GameState = PLAY;
        Init();
    }
}
