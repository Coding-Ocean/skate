#pragma once
#include"BUILDING.h"
#include"CLOUDS.h"
#include"OBSTACLE.h"
#include"PLAYER.h"
#include"SCORE.h"

class GAME
{
    //ゲームステート
    int GameState;
    enum {TITLE,PLAY,RESULT};
    void Title();
    void Play();
    void Result();

    void LoadAssets();
    void Init();//初期化およびリセット
    int NumMoves;
    int NumObstacleAvoided;

    //キャラクタ
    BUILDING Building;
    CLOUDS Clouds;
    OBSTACLE Obstacle; 
    PLAYER Player;
    SCORE Score;
public:
    GAME();
    void run();

    OBSTACLE* obstacle() { return &Obstacle; }
};

