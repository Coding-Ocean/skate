#pragma once
#include"BUILDING.h"
#include"CLOUDS.h"

class GAME
{
    //�Q�[���X�e�[�g
    int GameState;
    enum {TITLE,PLAY,RESULT};
    void Title();
    void Play();
    void Result();

    void LoadAssets();
    void Init();//����������у��Z�b�g
    //�L�����N�^
    BUILDING Building;
    CLOUDS Clouds;
public:
    GAME();
    void run();
};

