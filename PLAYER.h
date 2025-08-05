#pragma once
class PLAYER
{
    int BoyImg[4];
    int BoyImgIdx;
    enum {STANDING, CROUCHING, CRUSH, DOWN};
    float BoyPx, BoyPy;
    int BoyJumpFlag;
    float BoyVy, BoyHighJumpInitVy, BoyLowJumpInitVy, Gravity;

    int SkeboImg;
    float SkeboPx;
    float SkeboPy;

    class GAME* Game;
    int SaveObstacleType;
public:
    PLAYER(class GAME* game);
    void cutImg(int imgs);
    void init();
    void move();
    void draw();
};

