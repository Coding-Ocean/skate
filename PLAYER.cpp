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
            SaveObstacleType = obstacle.type();//��񂾏u�Ԃ̏�Q���^�C�v������Ă���
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
        //�W�����v
        BoyPy += BoyVy * 60 * delta;
        BoyVy += Gravity * delta;
        //��Q�������i�̎�
        if (SaveObstacleType == OBSTACLE::LOWER) {
            //�X�P�{�[�Ƃ�������ɃW�����v
            SkeboPy = BoyPy + 120;
            //���i�u���b�N�ɏ������
            float rightTireCenterX = SkeboPx + 69;//�E���̃^�C���̒��SX���W
            float leftTireCenterX = SkeboPx + 24;//�����̃^�C���̒��SX���W
            if (rightTireCenterX >= obstacle.left() && leftTireCenterX <= obstacle.right()) {
                if (BoyPy >= 200) {
                    BoyPy = 200;
                }
            }
        }
        //���n
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

    //��i�u���b�N�܂��̓J���X
    if (obstacle.type() == OBSTACLE::UPPER || obstacle.type() == OBSTACLE::CROW) {
        if (BoyRight() > obstacle.left() && BoyLeft() < obstacle.right()) {
            if (BoyImgIdx == STANDING) {
                BoyImgIdx = CRUSH;
                return true;
            }
        }
    }

    //���i�u���b�N
    if (obstacle.type() == OBSTACLE::MIDDLE) {
        if (BoyRight() > obstacle.left() && BoyLeft() < obstacle.right()) {
            if (BoyPy >= 190) { //�u���b�N�̍��ɂԂ�����(���N�̍����Ŕ��f)
                BoyImgIdx = CRUSH;
                return true;
            }
            if (BoyPy >= 160) { //�u���b�N�̏�ɂԂ�����(���N�̍����Ŕ��f)
                BoyPx += 60;
                BoyPy = 160;
                BoyImgIdx = DOWN;
                return true;
            }
        }
    }

    //���i�u���b�N
    if (obstacle.type() == OBSTACLE::LOWER) {
        //�E�^�C���̒��S���u���b�N�̍��𒴂������A��������Ƃɂ���̂ŁA�����蔻��s�v�B        
        if (RightTireCenterX() >= obstacle.left()) {
            return false;
        }
        //�X�P�{�[�ƃu���b�N�̓����蔻��
        if (SkeboRight() >= obstacle.left() && SkeboBottom() >= obstacle.top()) {
            BoyPx += 60;
            BoyImgIdx = DOWN;
            return true;
        }
        //�E���̃^�C���ƃu���b�N�̓����蔻��
        float dx = obstacle.left() - RightTireCenterX();
        float dy = obstacle.top() - RightTireCenterY();
        dy = max(dy, 0.0f);//dy���}�C�i�X�i�u���b�N��[���^�C���̒��S�����j�̎���dy���O�Ƃ���
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