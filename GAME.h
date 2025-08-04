#pragma once
#include"BUILDING.h"

class GAME
{
    //ゲームステート
    int GameState;
    enum {TITLE,PLAY,RESULT};
    void Title();
    void Play();
    void Result();
    void Init();//初期化およびリセット
    //キャラクタ
    BUILDING Building;
public:
    GAME();
    void run();
};

