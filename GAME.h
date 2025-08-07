#pragma once
#include"BUILDING.h"
#include"CLOUDS.h"
#include"OBSTACLE.h"
#include"PLAYER.h"
#include"SCORE.h"

class GAME
{
    //アセット読み込み
    void LoadAssets();
    //初期化およびリセット
    void Init();
    //ゲームステート
    int GameState;
    enum {TITLE,PLAY,RESULT};
    void Title();
    void Play();
    void Result();
    //スピードコントロール
    int NumMoves;
    int NumToSpeedUp;
    //サウンド
    int TitleSnd;
    int BgmSnd;
    int GameOverSnd;

    //キャラクタ
    BUILDING Building;
    CLOUDS Clouds;
    OBSTACLE Obstacle; 
    PLAYER Player;
    SCORE Score;
    int GameOverLogoImg;
public:
    GAME();
    void run();
    //プレイヤーが参照する
    OBSTACLE* obstacle() { return &Obstacle; }
};

