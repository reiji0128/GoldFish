#include "UI.h"
#include"DxLib.h"
#include"PoiBase.h"



UI::UI()
    :timerImgX(0)
    ,timerImgY(0)
    ,timer(30)
    ,timerCounter(1)
    ,scoreImgY(20)
    ,nowScore(0)
{

}

UI::~UI()
{

}

void UI::Update(float deltaTime)
{
    timer -= timerCounter * deltaTime;
}

void UI::Draw()
{
    //DrawFormatString(timerImgX, timerImgY, GetColor(255, 255, 255), "%d", timer);
}