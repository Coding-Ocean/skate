#include "..\libOne\inc\libOne.h"
#include "GAME.h"

PLAYER::PLAYER()
{
    BoyHighJumpInitVy = -1.0f;
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
    if (!BoyJumpFlag) {
        if (isTrigger(KEY_UP)) {
            BoyJumpFlag = 1;
            BoyVy = BoyHighJumpInitVy;
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
        //ƒWƒƒƒ“ƒv
        BoyPy += BoyVy * 60 * delta;
        BoyVy += Gravity * delta;
        //’…’n
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