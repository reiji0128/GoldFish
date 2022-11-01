#include "Score.h"
#include"DxLib.h"

Score::Score()
    :scoreImgX()
    ,scoreImgY(20)
    ,nowScore(0)
{
    scoreImgX[1] = 1800;
}

Score::~Score()
{

}

void Score::Draw()
{
    for (int i = 0; i < 2; i++)
    {
        DrawFormatString(scoreImgX[i], scoreImgY, GetColor(255, 255, 255), "SCORE:%d", nowScore);
    }
}