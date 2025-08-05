#include "..\libOne\inc\libOne.h"
#include "GAME.h"

PLAYER::PLAYER(GAME* game)
    :Game(game)
{
    BoyHighJumpInitVy = -1.0f;
    BoyLowJumpInitVy = -0.7f;
    Gravity = 0.0045f * 60;

    SkeboTireRadiusSq = 13 * 13;
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

bool PLAYER::hitAnObstacle()
{
    OBSTACLE& obstacle = *Game->obstacle();

    //上段ブロックまたはカラス
    if (obstacle.type() == OBSTACLE::UPPER || obstacle.type() == OBSTACLE::CROW) {
        if (BoyRight() > obstacle.left() && BoyLeft() < obstacle.right()) {
            if (BoyImgIdx == STANDING) {
                BoyImgIdx = CRUSH;
                return true;
            }
        }
    }

    //中段ブロック
    if (obstacle.type() == OBSTACLE::MIDDLE) {
        if (BoyRight() > obstacle.left() && BoyLeft() < obstacle.right()) {
            if (BoyPy >= 190) { //ブロックの左にぶつかった(少年の高さで判断)
                BoyImgIdx = CRUSH;
                return true;
            }
            if (BoyPy >= 160) { //ブロックの上にぶつかった(少年の高さで判断)
                BoyPx += 60;
                BoyPy = 160;
                BoyImgIdx = DOWN;
                return true;
            }
        }
    }

    //下段ブロック
    if (obstacle.type() == OBSTACLE::LOWER) {
        //右タイヤの中心がブロックの左を超えた時、乗ったことにするので、当たり判定不要。        
        if (RightTireCenterX() >= obstacle.left()) {
            return false;
        }
        //スケボー板とブロックの当たり判定
        if (SkeboRight() >= obstacle.left() && SkeboBottom() >= obstacle.top()) {
            BoyPx += 60;
            BoyImgIdx = DOWN;
            return true;
        }
        //右側のタイヤとブロックの当たり判定
        float dx = obstacle.left() - RightTireCenterX();
        float dy = obstacle.top() - RightTireCenterY();
        dy = max(dy, 0.0f);//dyがマイナス（ブロック上端よりタイヤの中心が下）の時はdyを０とする
        if (SkeboTireRadiusSq > dx * dx + dy * dy) {
            BoyPx += 60;
            BoyImgIdx = DOWN;
            return true;
        }
    }

    return false;
}

void PLAYER::draw()
{
    image(BoyImg[BoyImgIdx], BoyPx, BoyPy);
    image(SkeboImg, SkeboPx, SkeboPy);
}