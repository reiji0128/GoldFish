#include "PoiBlue.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ
/// </summary>
PoiBlue::PoiBlue()
{
    mPadNum = DX_INPUT_PAD2;
    mPosX = 1440.0f;
    mPosY = 810.0f;
    LoadDivGraph("Img/Player/Scoop2.png", 5, 5, 1, (int)mScaleX, (int)mScaleY, mScoopImg);
    LoadDivGraph("Img/Player/Break2.png", 5, 5, 1, (int)mScaleX, (int)mScaleY, mBreakImg);
    mIsScoop = false;
    mIsFirstFrame = false;
    mPrevInput = false;
    mIsAlive = false;
}

/// <summary>
/// デストラクタ
/// </summary>
PoiBlue::~PoiBlue()
{
}
