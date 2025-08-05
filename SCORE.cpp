#include<fstream>
#include"../libOne/inc/libOne.h"
#include "SCORE.h"

SCORE::SCORE()
    :InitBlinkTime(0.8f)
{
}

void SCORE::cutImg(int imgs)
{
    for (int i = 0; i < 10; ++i) {
        ScoreImg[i] = cutImage(imgs, 100 + 30 * i, 122, 30, 40);
        HiScoreImg[i] = cutImage(imgs, 440 + 20 * i, 122, 20, 20);
    }
    HiScoreLogoImg = cutImage(imgs, 440, 140, 120, 20);
    NewRecordImg = cutImage(imgs, 230, 175, 100, 20);
}

void SCORE::init()
{
    Score = 0;
    NewRecordFlag = 0;
    BlinkTime = 0;
}

void SCORE::up()
{
    Score += 10;
}

void SCORE::draw()
{
    fill(255);
    //メインスコア
    int score = Score;
    int kurai = 1000;
    for (int i = 0; i < 4; ++i) {
        int idx = score / kurai;
        image(ScoreImg[idx], 270 + 25 * i, 0);
        score %= kurai;
        kurai /= 10;
    }
    //ハイスコア
    score = HiScore;
    kurai = 1000;
    for (int i = 0; i < 4; ++i) {
        int idx = score / kurai;
        image(HiScoreImg[idx], 560 + 20 * i, 2);
        score %= kurai;
        kurai /= 10;
    }
    image(HiScoreLogoImg, 440, 0);
    //新記録ロゴの点滅
    if (NewRecordFlag) {
        BlinkTime -= delta;
        if (BlinkTime < 0) {
            BlinkTime = InitBlinkTime;
        }
        if (BlinkTime > InitBlinkTime/2) {
            image(NewRecordImg, 270, 35);
        }
    }
}

void SCORE::newRecordCheck()
{
    if (Score > HiScore) {
        HiScore = Score;
        NewRecordFlag = 1;
    }
}

void SCORE::loadHiScore()
{
    std::ifstream fin("assets/score.txt");
    if (fin.is_open()) {
        fin >> HiScore;
    }
    else {
        HiScore = 0;
    }
    
    //HiScore = 0;//デバッグ用
}

void SCORE::saveHiScore()
{
    std::ofstream fout("assets/score.txt");
    if (fout.is_open()) {
        fout << HiScore;
    }
}
