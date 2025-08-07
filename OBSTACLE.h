#pragma once

class OBSTACLE
{
    int Type;//0=上段、1=中段、2=下段、3=カラス
    int BlockImg;
    int BlockImgW;
    int BlockImgH;
    int CrowImg[2];
    float Px, Py, Vx;
    //カラスのアニメーション切り替え
    int CrowImgIdx;
    float CrowImgSwichInterval;//切り替える時間
    float CrowTimeRemaining;//切り替えまでの残り時間
    //障害物の出現処理
    void Appear();
    int NumAppeared;
    //サウンド
    int CrowSnd;
public:
    enum TYPE{UPPER,MIDDLE,LOWER,CROW};
    OBSTACLE();
    void cutImg(int imgs);
    void loadSnd();
    void init();
    void move();
    void draw();
    //PLAYERとの当たり判定用
    int type() { return Type; }
    float left() { return Px; }
    float right() { return Type == CROW ? Px + 53 : Px + 80; }
    float top() { return Py; }
    //これがtrueの時、障害物が現れた瞬間となる。
    bool momentAppeared() { return Px == 640.0f; }
    int numAppeared() { return NumAppeared; }
};

