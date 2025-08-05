#pragma once
#include"BUILDING.h"
#include"CLOUDS.h"
#include"OBSTACLE.h"
#include"PLAYER.h"

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

    //キャラクタ
    BUILDING Building;
    CLOUDS Clouds;
    OBSTACLE Obstacle; 
    PLAYER Player;
public:
    GAME();
    void run();
};

