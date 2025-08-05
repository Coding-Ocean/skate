#include"..\libOne\inc\libOne.h"
#include "CLOUDS.h"

CLOUDS::CLOUDS()
{
    NumClouds = 6;
    Clouds = new CLOUD[NumClouds];
}

CLOUDS::~CLOUDS()
{
    delete[] Clouds;
}

void CLOUDS::cutImg(int imgs)
{
    int img0 = cutImage(imgs,   0, 165, 100, 50);
    int img1 = cutImage(imgs, 100, 165, 100, 50);
    for (int i = 0; i < NumClouds; ++i) {
        Clouds[i].img = img0 + random() % 2;
        Clouds[i].px = 120 * i + random() % 100;
        Clouds[i].py = 69 + random() % 150;
        Clouds[i].vx = -0.2f*60;
    }
}

void CLOUDS::move()
{
    for (int i = 0; i < NumClouds; ++i) {
        Clouds[i].px += Clouds[i].vx * delta;
        if (Clouds[i].px <= -100) {
            Clouds[i].px = 640;
        }
    }
}

void CLOUDS::draw()
{
    for (int i = 0; i < NumClouds; ++i) {
        image(Clouds[i].img, Clouds[i].px, Clouds[i].py);
    }
}