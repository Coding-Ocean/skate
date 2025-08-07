#pragma once
#include"BUILDING.h"
#include"CLOUDS.h"
#include"OBSTACLE.h"
#include"PLAYER.h"
#include"SCORE.h"

class GAME
{
    //�A�Z�b�g�ǂݍ���
    void LoadAssets();
    //����������у��Z�b�g
    void Init();
    //�Q�[���X�e�[�g
    int GameState;
    enum {TITLE,PLAY,RESULT};
    void Title();
    void Play();
    void Result();
    //�X�s�[�h�R���g���[��
    int NumMoves;
    int NumToSpeedUp;
    //�T�E���h
    int TitleSnd;
    int BgmSnd;
    int GameOverSnd;

    //�L�����N�^
    BUILDING Building;
    CLOUDS Clouds;
    OBSTACLE Obstacle; 
    PLAYER Player;
    SCORE Score;
    int GameOverLogoImg;
public:
    GAME();
    void run();
    //�v���C���[���Q�Ƃ���
    OBSTACLE* obstacle() { return &Obstacle; }
};

