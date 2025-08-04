#pragma once

class GAME
{
    //ゲームステート
    int GameState;
    enum {TITLE,PLAY,RESULT};
    void Title();
    void Play();
    void Result();
    void Init();//初期化およびリセット
public:
    GAME();
    void run();
};

