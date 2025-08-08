#include"..\libOne\inc\libOne.h"
#include"GAME.h"
#include "OBSTACLE.h"


OBSTACLE::OBSTACLE()
{
    Vx = -1.0f * 60.0f;
    CrowImgSwichInterval = 1.2f;
}

void OBSTACLE::cutImg(int imgs)
{
    BlockImgW = 80;
    BlockImgH = 40;
    BlockImg = cutImage(imgs, 560, 80, BlockImgW, BlockImgH);
    CrowImg[0] = cutImage(imgs, 420, 165, 100, 60);
    CrowImg[1] = cutImage(imgs, 520, 165, 100, 60);
}

void OBSTACLE::loadSnd()
{
    CrowSnd = ::loadSound("assets/crow.wav");
}

void OBSTACLE::init()
{
    NumAppeared = 0;
    Appear();
}

void OBSTACLE::Appear()
{
    Px = 640;

    //20より小さい時、カラスを出現させない
    NumAppeared++;
    if (NumAppeared < 20) {
        Type = random() % 3;
    }
    else {
        Type = random() % 4;
    }

    //Type別にｙ座標を決定
    if (Type == UPPER) {
        Py = 0;
    }
    else if (Type == MIDDLE) {
        Py = 280;
    }
    else if (Type == LOWER) {
        Py = 360;
    }
    else if (Type == CROW) {
        Py = 230;
        CrowTimeRemaining = 0;
        CrowImgIdx = 0;
        playSound(CrowSnd);
    }
}

void OBSTACLE::move()
{
    //動かす
    Px += Vx * delta;
    if (Px < -100) {
        Appear();
    }
    //カラスアニメーション
    if (Type == CROW) {
        CrowTimeRemaining -= delta;
        if (CrowTimeRemaining < 0.0f) {
            CrowTimeRemaining = CrowImgSwichInterval;
            CrowImgIdx = 1 - CrowImgIdx;
        }
    }
}

void OBSTACLE::draw()
{
    if (Type == UPPER) {
        for (int i = 0; i < 7; ++i) {
            image(BlockImg, Px, Py + BlockImgH * i);
        }
    }
    else if (Type == MIDDLE) {
        image(BlockImg, Px, Py);
        image(BlockImg, Px, Py + BlockImgH);
    }
    else if (Type == LOWER) {
        image(BlockImg, Px, Py);
    }
    else if (Type == CROW) {
        image(CrowImg[CrowImgIdx], Px, Py);
    }
}