#include"..\libOne\inc\libOne.h"
#include "GAME.h"

GAME::GAME()
    :Player(this)
{
}

void GAME::run()
{
    window(640, 433);
    LoadAssets();
    Score.loadHiScore();
    GameState = TITLE;
    initDeltaTime();
    while (notQuit)
    {
        setDeltaTime();
        if      (GameState == TITLE ) { Title(); }
        else if (GameState == PLAY  ) { Play(); }
        else if (GameState == RESULT) { Result(); }
    }
    Score.saveHiScore();
}

void GAME::LoadAssets()
{
    int imgs = loadImage("assets/skate.png");
    Building.cutImg(imgs);
    Clouds.cutImg(imgs);
    Obstacle.cutImg(imgs);
    Player.cutImg(imgs);
    Score.cutImg(imgs);
}

void GAME::Init()
{
    Obstacle.init();
    Player.init();
    Score.init();
    NumMoves = 7;
    NumObstacleAvoided = 0;
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
    for (int i = 0; i < NumMoves; ++i) {
 
        //move
        Building.move();
        Clouds.move();
        Obstacle.move();
        Player.move();

        //speed up 
        if (Obstacle.nextOneAppeared()) {
            Score.up();
            if (++NumObstacleAvoided % 10 == 0) {
                ++NumMoves;
                ++i;
            }
        }

        //next state
        if (Player.hitAnObstacle()) {
            GameState = RESULT;
            Score.newRecordCheck();
            return;
        }
    }

    //draw
    clear();
    fill(64, 128, 255);
    rect(0, 0, width, height);
    Building.draw();
    Clouds.draw();
    Obstacle.draw();
    Player.draw();
    Score.draw();
}

void GAME::Result()
{
    //draw
    clear();
    fill(64, 128, 255);
    rect(0, 0, width, height);
    Building.draw();
    Clouds.draw();
    Obstacle.draw();
    Player.draw();
    Score.draw();
    fill(255, 255, 255);
    text("ゲームオーバー", 100, 100);
    text("Push \"Enter\" to restart.", 200, 280);

    //next state
    if (isTrigger(KEY_ENTER)) {
        GameState = PLAY;
        Init();
    }
}
