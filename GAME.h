#pragma once
#include"BUILDING.h"

class GAME
{
    //�Q�[���X�e�[�g
    int GameState;
    enum {TITLE,PLAY,RESULT};
    void Title();
    void Play();
    void Result();
    void Init();//����������у��Z�b�g
    //�L�����N�^
    BUILDING Building;
public:
    GAME();
    void run();
};

