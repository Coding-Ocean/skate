#include"..\libOne\inc\libOne.h"
#include "GAME.h"

GAME::GAME()
    :Player(this)
    ,NumToSpeedUp(10)
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
    GameOverLogoImg = cutImage(imgs, 0, 230, 640, 60);

    TitleSnd = loadSound("assets/title.wav");
    BgmSnd = loadSound("assets/bgm.wav");
    GameOverSnd = loadSound("assets/gameOver.wav");
    Obstacle.loadSnd();
    Player.loadSnd();

    playLoopSound(TitleSnd);
}

void GAME::Init()
{
    Obstacle.init();
    Player.init();
    Score.init();
    NumMoves = 7;
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
        stopSound(TitleSnd);
        playLoopSound(BgmSnd);
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

        //score up and speed up 
        if (Obstacle.momentAppeared()) {
            Score.up();
            if (Obstacle.numAppeared() % NumToSpeedUp == 0) {
                ++NumMoves;
            }
        }

        //next state
        if (Player.hitAnObstacle()) {
            GameState = RESULT;
            Score.newRecordCheck();
            stopSound(BgmSnd);
            playSound(GameOverSnd);
            return;
        }
    }

    //draw
    clear();
    Building.draw();
    Clouds.draw();
    Obstacle.draw();
    Player.draw();
    Score.draw();
}

void GAME::Result()
{
    Clouds.move();

    //draw
    clear();
    Building.draw();
    Clouds.draw();
    Obstacle.draw();
    Player.draw();
    Score.draw();
    image(GameOverLogoImg, 0, 150);
    fill(255, 255, 255);
    text("Push \"Enter\" to restart.", 200, 280);

    //next state
    if (isTrigger(KEY_ENTER)) {
        GameState = PLAY;
        Init();
        stopSound(GameOverSnd);
        playLoopSound(BgmSnd);
    }
}
