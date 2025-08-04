#pragma once
class BUILDING
{
    int Img;
    float Px, Py, Vx;
public:
    BUILDING();
    void cutImg(int imgs);
    void move();
    void draw();
};