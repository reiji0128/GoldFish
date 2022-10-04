#include "PoiRed.h"
#include "DxLib.h"

PoiRed::PoiRed()
{
    mPadNum = DX_INPUT_PAD1;
    mPosX = 480.0f;
    mPosY = 810.0f;
    LoadDivGraph("Img/Player/Scoop.png", 5, 5, 1, (int)mScaleX, (int)mScaleY, mScoopImg);
    LoadDivGraph("Img/Player/Break.png", 5, 5, 1, (int)mScaleX, (int)mScaleY, mBreakImg);
}

PoiRed::~PoiRed()
{
}
