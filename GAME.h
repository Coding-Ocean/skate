#pragma once
#include"BUILDING.h"
#include"CLOUDS.h"
#include"OBSTACLE.h"
#include"PLAYER.h"
#include"SCORE.h"

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
    int NumObstacleAvoided;

    //�L�����N�^
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

