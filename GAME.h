#pragma once

class GAME
{
    //�Q�[���X�e�[�g
    int GameState;
    enum {TITLE,PLAY,RESULT};
    void Title();
    void Play();
    void Result();
    void Init();//����������у��Z�b�g
public:
    GAME();
    void run();
};

