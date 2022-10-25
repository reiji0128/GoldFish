#include "PoiBlue.h"
#include "DxLib.h"
#include "Collision.h"

/// <summary>
/// コンストラクタ
/// </summary>
PoiBlue::PoiBlue()
{
    mPadNum = DX_INPUT_PAD2;
    mPosX = 1440.0f;
    mPosY = 810.0f;
    LoadDivGraph("Img/Player/Break2.png", 5, 5, 1, (int)mScaleX, (int)mScaleY, mBreakImg);
    LoadDivGraph("Img/Player/Scoop2.png", 6, 6, 1, (int)mScaleX, (int)mScaleY, mScoopImg);
    const char* brokenGrahp = "Img/Player/Broken2.png";
    mBrokenImg = LoadGraph(brokenGrahp);
    mBrokenImgF = LoadGraph(brokenGrahp);
    GraphFilter(mBrokenImgF, DX_GRAPH_FILTER_HSB, 0, 0, 0, 150);
    mIsScoop = false;
    mIsFirstFrame = false;
    mPrevInput = false;
    mIsAlive = true;
}

/// <summary>
/// デストラクタ
/// </summary>
PoiBlue::~PoiBlue()
{
}

void PoiBlue::Update(float deltaTime)
{
    Move(deltaTime);

    AdjustPos();

    Bonus(deltaTime);

    Scoop(deltaTime);

    CheckHP();

    Repair(deltaTime);

    Collision::CollUpdateP(mPosX, mPosY, mHalfScaleX, 1);
}
