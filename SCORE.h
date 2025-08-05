#pragma once
class SCORE
{
    int ScoreImg[10];
    int Score;

    int HiScoreImg[10];
    int HiScoreLogoImg;
    int HiScore;

    int NewRecordImg;
    int NewRecordFlag;
    float BlinkTime;
    const float InitBlinkTime;
public:
    SCORE();
    void cutImg(int imgs);
    void init();
    void up();
    void draw();
    void newRecordCheck();
    void loadHiScore();
    void saveHiScore();
};

