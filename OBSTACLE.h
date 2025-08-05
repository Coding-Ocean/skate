#pragma once


class OBSTACLE
{
    int Type;//0=上段、1=中段、2=下段、3=カラス
    int BlockImg;
    int BlockImgW;
    int BlockImgH;
    int CrowImg[2];
    float Px, Py, Vx;
    //アニメーション切り替え
    int CrowImgIdx;
    float CrowImgSwichInterval;//切り替える時間
    float CrowTimeRemaining;//切り替えまでの残り時間
public:
    enum TYPE{UPPER,MIDDLE,LOWER,CROW};
    OBSTACLE();
    void cutImg(int imgs);
    void init();
    void move();
    void draw();
    //PLAYERとの当たり判定用
    int type() { return Type; }
    float left() { return Px; }
    float right() { return Px + BlockImgW; }
    float top() { return Py; }
    //これがtrueの時、次の障害物が現れたことになる。GAMEクラスでスピードアップのきっかけとして使う
    bool nextOneAppeared() { return Px == 640.0f; }
};

