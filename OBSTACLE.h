#pragma once

class OBSTACLE
{
    int Type;//0=��i�A1=���i�A2=���i�A3=�J���X
    int BlockImg;
    int BlockImgW;
    int BlockImgH;
    int CrowImg[2];
    float Px, Py, Vx;
    //�J���X�̃A�j���[�V�����؂�ւ�
    int CrowImgIdx;
    float CrowImgSwichInterval;//�؂�ւ��鎞��
    float CrowTimeRemaining;//�؂�ւ��܂ł̎c�莞��
    //��Q���̏o������
    void Appear();
    int NumAppeared;
    //�T�E���h
    int CrowSnd;
public:
    enum TYPE{UPPER,MIDDLE,LOWER,CROW};
    OBSTACLE();
    void cutImg(int imgs);
    void loadSnd();
    void init();
    void move();
    void draw();
    //PLAYER�Ƃ̓����蔻��p
    int type() { return Type; }
    float left() { return Px; }
    float right() { return Type == CROW ? Px + 53 : Px + 80; }
    float top() { return Py; }
    //���ꂪtrue�̎��A��Q�������ꂽ�u�ԂƂȂ�B
    bool momentAppeared() { return Px == 640.0f; }
    int numAppeared() { return NumAppeared; }
};

