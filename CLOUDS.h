#pragma once
class CLOUDS
{
    int NumClouds;
    struct CLOUD {
        int img;
        float px, py, vx;
    }*Clouds;
public:
    CLOUDS();
    ~CLOUDS();
    void cutImg(int imgs);
    void move();
    void draw();
};

