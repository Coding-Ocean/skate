#pragma once
class PLAYER
{
    int BoyImg[4];
    int BoyImgIdx;
    enum {STANDING, CROUCHING, CRUSH, DOWN};
    float BoyPx, BoyPy;
    int BoyJumpFlag;
    float BoyVy, BoyHighJumpInitVy, Gravity;

    int SkeboImg;
    float SkeboPx;
    float SkeboPy;
public:
    PLAYER();
    void cutImg(int imgs);
    void init();
    void move();
    void draw();
};

