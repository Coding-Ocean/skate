#include"..\libOne\inc\libOne.h"
#include "BUILDING.h"

BUILDING::BUILDING()
{
    Px = 0;
    Py = 295;
    Vx = -0.4f*60;
}

void BUILDING::cutImg(int imgs)
{
    Img = cutImage(imgs, 0, 295, 640, 138);
}

void BUILDING::move()
{
    Px += Vx * delta;
    if (Px <= -640) {
        Px = 0;
    }
}

void BUILDING::draw()
{
    fill(64, 128, 255);
    rect(0, 0, 640, 480);
    image(Img, Px, Py);
    image(Img, Px+640, Py);
}
