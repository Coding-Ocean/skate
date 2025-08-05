#pragma once
#include"BUILDING.h"
#include"CLOUDS.h"

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
    //キャラクタ
    BUILDING Building;
    CLOUDS Clouds;
public:
    GAME();
    void run();
};

