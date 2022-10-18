#include "PoiRed.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ
/// </summary>
PoiRed::PoiRed()
{
    mPadNum = DX_INPUT_PAD1;
    mPosX = 480.0f;
    mPosY = 810.0f;
    LoadDivGraph("Img/Player/Break.png", 5, 5, 1, (int)mScaleX, (int)mScaleY, mBreakImg);
    LoadDivGraph("Img/Player/Scoop.png", 6, 6, 1, (int)mScaleX, (int)mScaleY, mScoopImg);
    mBrokenImg = LoadGraph("Img/Player/Broken.png");
    mBrokenImgF = mBrokenImg;
    mIsScoop = false;
    mIsFirstFrame = false;
    mPrevInput = false;
    mIsAlive = false;
}

/// <summary>
/// デストラクタ
/// </summary>
PoiRed::~PoiRed()
{
}
