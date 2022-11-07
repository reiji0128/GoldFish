#include "PoiRed.h"
#include "DxLib.h"
#include "Collision.h"

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
    const char* brokenGraph = "Img/Player/Broken.png";
    mBrokenImg = LoadGraph(brokenGraph);
    mBrokenImgF = LoadGraph(brokenGraph);
    GraphFilter(mBrokenImgF, DX_GRAPH_FILTER_HSB, 0, 0, 0, 150);
    mIsScoop = false;
    mIsFirstFrame = false;
    mPrevInput = false;
    mIsAlive = true;
}

/// <summary>
/// デストラクタ
/// </summary>
PoiRed::~PoiRed()
{
}

void PoiRed::Update(float deltaTime)
{
    Move(deltaTime);

    AdjustPos();

    Bonus(deltaTime);

    Scoop(deltaTime);

    CheckHP();

    Repair(deltaTime);

    Collision::PlayerCollUpdate(mPosX, mPosY, mHalfScaleX, mIsScoop, 0);
}