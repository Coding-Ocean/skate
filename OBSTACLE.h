#pragma once


class OBSTACLE
{
    int Type;//0=��i�A1=���i�A2=���i�A3=�J���X
    int BlockImg;
    int BlockImgW;
    int BlockImgH;
    int CrowImg[2];
    float Px, Py, Vx;
    //�A�j���[�V�����؂�ւ�
    int CrowImgIdx;
    float CrowImgSwichInterval;//�؂�ւ��鎞��
    float CrowTimeRemaining;//�؂�ւ��܂ł̎c�莞��
public:
    enum TYPE{UPPER,MIDDLE,LOWER,CROW};
    OBSTACLE();
    void cutImg(int imgs);
    void init();
    void move();
    void draw();
    //PLAYER�Ƃ̓����蔻��p
    int type() { return Type; }
    float left() { return Px; }
    float right() { return Px + BlockImgW; }
    float top() { return Py; }
    //���ꂪtrue�̎��A���̏�Q�������ꂽ���ƂɂȂ�BGAME�N���X�ŃX�s�[�h�A�b�v�̂��������Ƃ��Ďg��
    bool nextOneAppeared() { return Px == 640.0f; }
};

