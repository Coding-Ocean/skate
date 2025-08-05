#include "..\libOne\inc\libOne.h"
#include "GAME.h"

PLAYER::PLAYER(GAME* game)
    :Game(game)
{
    BoyHighJumpInitVy = -1.0f;
    BoyLowJumpInitVy = -0.7f;
    Gravity = 0.0045f * 60;
}

void PLAYER::cutImg(int imgs)
{
    BoyImg[STANDING]  = cutImage(imgs, 0, 0, 100, 120);
    BoyImg[CROUCHING] = cutImage(imgs, 100, 0, 100, 120);
    BoyImg[CRUSH]     = cutImage(imgs, 200, 0, 100, 120);
    BoyImg[DOWN]      = cutImage(imgs, 300, 0, 120, 120);

    SkeboImg = cutImage(imgs, 0, 120, 100, 40);
}

void PLAYER::init()
{
    BoyPx = 20;
    BoyPy = 240;
    BoyJumpFlag = 0;
    BoyImgIdx = STANDING;

    SkeboPx = BoyPx;
    SkeboPy = BoyPy + 120;
}

void PLAYER::move()
{
    OBSTACLE& obstacle = *Game->obstacle();

    if (!BoyJumpFlag) {
        if (isTrigger(KEY_UP)) {
            BoyJumpFlag = 1;
            SaveObstacleType = obstacle.type();//飛んだ瞬間の障害物タイプを取っておく
            if (SaveObstacleType == OBSTACLE::LOWER) {
                BoyVy = BoyLowJumpInitVy;
            }
            else {
                BoyVy = BoyHighJumpInitVy;
            }
            BoyImgIdx = STANDING;
        }
        else {
            if (isPress(KEY_DOWN)) {
                BoyImgIdx = CROUCHING;
            }
            else {
                BoyImgIdx = STANDING;
            }
        }
    }

    if (BoyJumpFlag) {
        //ジャンプ
        BoyPy += BoyVy * 60 * delta;
        BoyVy += Gravity * delta;
        //障害物が下段の時
        if (SaveObstacleType == OBSTACLE::LOWER) {
            //スケボーといっしょにジャンプ
            SkeboPy = BoyPy + 120;
            //下段ブロックに乗っける
            float rightTireCenterX = SkeboPx + 69;//右側のタイヤの中心X座標
            float leftTireCenterX = SkeboPx + 24;//左側のタイヤの中心X座標
            if (rightTireCenterX >= obstacle.left() && leftTireCenterX <= obstacle.right()) {
                if (BoyPy >= 200) {
                    BoyPy = 200;
                }
            }
        }
        //着地
        if (BoyPy > 240) {
            BoyJumpFlag = 0;
            BoyPy = 240;
            SkeboPy = BoyPy + 120;
        }
    }
}

void PLAYER::draw()
{
    image(BoyImg[BoyImgIdx], BoyPx, BoyPy);
    image(SkeboImg, SkeboPx, SkeboPy);
}