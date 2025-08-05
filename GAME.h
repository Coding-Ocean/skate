#pragma once
#include"BUILDING.h"
#include"CLOUDS.h"
#include"OBSTACLE.h"
#include"PLAYER.h"

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
    int NumMoves;

    //�L�����N�^
    BUILDING Building;
    CLOUDS Clouds;
    OBSTACLE Obstacle; 
    PLAYER Player;
public:
    GAME();
    void run();
};

