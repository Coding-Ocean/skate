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
    float SkeboTireRadiusSq;
    float BoyRight() { return BoyPx + 60; }
    float BoyLeft() { return BoyPx + 38; }
    float SkeboRight() { return SkeboPx + 97; }
    float SkeboBottom() { return SkeboPy + 11; }
    float LeftTireCenterX() { return SkeboPx + 24; }
    float RightTireCenterX() { return SkeboPx + 69; }
    float RightTireCenterY() { return SkeboPy + 27; }

    int HighJumpSnd;
    int LowJumpSnd;
    int ClouchingSnd;

public:
    PLAYER(class GAME* game);
    void cutImg(int imgs);
    void loadSnd();
    void init();
    void move();
    bool hitAnObstacle();
    void draw();
};

