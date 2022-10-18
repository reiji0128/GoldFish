#include "PoiBase.h"
#include "DxLib.h"
#include "FishManager.h"
#include <math.h>

/// <summary>
/// コンストラクタ
/// </summary>
PoiBase::PoiBase()
    :mPosX(0)
    ,mPosY(0)
    ,mScaleX(128.0f)
    ,mScaleY(256.0f)
    ,mFloatScale(1.0f)
    ,mHalfScaleX(mScaleX/2)
    ,mHalfScaleY(mScaleY/2)
    ,mPadNum(0)
    ,mInputX(0)
    ,mInputY(0)
    ,mSpeed(400.0f)
    ,mImage(0)
    ,mBrokenImg(0)
    ,mBrokenImgF(0)
    ,mIsFlash(false)
    ,mIsScoop(false)
    ,mIsFirstFrame(false)
    ,mPrevInput(false)
    ,mAnimCounter(0)
    ,mAnimNum(0)
    ,mBonusCount(0)
    ,mBonusTimer(0)
    ,hp(24)
    ,mIsAlive(true)
    ,deadTime(0)
    ,mScore(0)
{
}

/// <summary>
/// デストラクタ
/// </summary>
PoiBase::~PoiBase()
{
    // 画像の破棄
    DeleteGraph(mImage);
    for (int i = 0; i < 5; i++)
    {
        DeleteGraph(mBreakImg[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        DeleteGraph(mScoopImg[i]);
    }
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="deltaTime">1フレームの経過時間</param>
void PoiBase::Update(float deltaTime)
{
    Move(deltaTime);

    AdjustPos();

    Bonus(deltaTime);

    Scoop(deltaTime);

    CheckHP();

    Repair(deltaTime);

}

/// <summary>
/// 描画処理
/// </summary>
void PoiBase::Draw()
{
    DrawRotaGraph((int)mPosX, (int)mPosY, mFloatScale, 0, mImage, TRUE);
}

/// <summary>
/// 移動処理
/// </summary>
/// <param name="deltaTime">1フレームの経過時間</param>
void PoiBase::Move(float deltaTime)
{
    // スティックの入力状態を取得
    GetJoypadAnalogInput(&mInputX, &mInputY, mPadNum);

    // 右に倒れていたら
    if (mInputX > 0)
    {
        mPosX += mSpeed * deltaTime;
    }

    // 左に倒れていたら
    if (mInputX < 0)
    {
        mPosX -= mSpeed * deltaTime;
    }

    // 上に倒れていたら
    if (mInputY > 0)
    {
        mPosY += mSpeed * deltaTime;
    }

    // 下に倒れたいたら
    if (mInputY < 0)
    {
        mPosY -= mSpeed * deltaTime;
    }
}

/// <summary>
/// 位置調整処理
/// </summary>
void PoiBase::AdjustPos()
{
    // 画面左端に接触したら
    if (mPosX < 0 + (mHalfScaleX * mFloatScale))
    {
        mPosX = 0 + (mHalfScaleX * mFloatScale);
    }

    // 画面右端に接触したら
    if (mPosX > 1920 - (mHalfScaleX * mFloatScale))
    {
        mPosX = 1920 - (mHalfScaleX * mFloatScale);
    }

    // 画面上に接触したら
    if (mPosY < 0 + (mHalfScaleY * mFloatScale))
    {
        mPosY = 0 + (mHalfScaleY * mFloatScale);
    }

    // 画面下に接触したら
    if (mPosY >= 1080)
    {
        mPosY = 1080;
    }
}

/// <summary>
/// 掬う処理
/// </summary>
/// <param name="deltaTime">1フレームの経過時間</param>
void PoiBase::Scoop(float deltaTime)
{
    // ボタンが押されていなかったら
    if ((GetJoypadInputState(mPadNum) & PAD_INPUT_3) == 0)
    {
        // 前フレームで押されていないことにする
        mPrevInput = false;
    }
    else
    {
        // 前フレームでの入力がなく、掬っていない状態で、生きていたら
        if (!mPrevInput && !mIsScoop && mIsAlive)
        {
            // 掬っている状態を保存する
            mIsScoop = true;
            // 1フレーム目であることを保存する
            mIsFirstFrame = true;
            // 入力されたことを保存する
            mPrevInput = true;
            // 入水時の体力減少
            hp -= 3;
        }
        if (hp > 0)
        {
            mIsAlive = true;
        }
        else
        {
            mIsAlive = false;
        }
    }

    // 生きていて掬っているなら
    if (mIsAlive && mIsScoop)
    {
        // 1フレーム目なら
        if (mIsFirstFrame)
        {
            // アニメーションのカウンタ初期化
            mAnimCounter = 0;
            mIsFirstFrame = false;

            // 当たり判定を調べる
            //Coll();
        }
        mAnimCounter += deltaTime;
        mAnimNum = int(mAnimCounter * 12);
        mImage = mScoopImg[mAnimNum];
        if (mAnimNum >= 6)
        {
            mIsScoop = false;
        }
    }
    else
    {
        mIsFirstFrame = false;
    }
}

/// <summary>
/// 体力確認処理
/// </summary>
void PoiBase::CheckHP()
{
    if (!mIsScoop)
    {
        if (hp < 1)
        {
            mImage = mBreakImg[4];
        }
        else if (hp >= 1 && hp < 8)
        {
            mImage = mBreakImg[3];
        }
        else if (hp >= 8 && hp < 16)
        {
            mImage = mBreakImg[2];
        }
        else if (hp >= 16 && hp < 24)
        {
            mImage = mBreakImg[1];
        }
        else if (hp == 24)
        {
            mImage = mBreakImg[0];
        }
    }
}

/// <summary>
/// 修理処理
/// </summary>
/// <param name="deltaTime">1フレームの経過時間</param>
void PoiBase::Repair(float deltaTime)
{
    if (!mIsAlive)
    {
        deadTime += deltaTime;
    }

    if (deadTime > 3.0f)
    {
        deadTime = 0;
        mIsAlive = true;
        hp = 24;
    }
}

/// <summary>
/// ボーナス処理
/// </summary>
/// <param name="deltaTime">1フレームの経過時間</param>
void PoiBase::Bonus(float deltaTime)
{
    if (mBonusCount > 2)
    {
        mIsBonus = true;
    }
    else
    {
        mIsBonus = false;
    }

    if (mIsBonus)
    {
        mFloatScale = 2.0f;
        mBonusTimer += deltaTime;
    }
    else
    {
        mFloatScale = 1.0f;
    }

    if (mBonusTimer > 5.0f)
    {
        mBonusTimer = 0;
        mBonusCount = 0;
        mIsBonus = false;
    }
}

/// <summary>
/// スコアの計算
/// </summary>
/// <param name="tag">金魚の種類</param>
void PoiBase::CalcScore(Tag tag)
{
    // 同じ色の金魚を掬ったら
    if ((tag == Tag::RedFish) && mPadNum == DX_INPUT_PAD1 ||
        (tag == Tag::BlueFish && mPadNum == DX_INPUT_PAD2))
    {
        mScore += 10;
        hp -= 3;
        mBonusCount++;
    }

    // お互いの色の金魚を掬ったら
    if ((tag == Tag::RedFish && mPadNum == DX_INPUT_PAD2) || 
        (tag == Tag::BlueFish && mPadNum == DX_INPUT_PAD1))
    {
        hp -= 4;
    }

    // 金の金魚を掬ったら
    if (tag == Tag::GoldFish)
    {
        mScore += 20;
        hp -= 5;
    }

    // 黒の金魚を掬ったら
    if (tag == Tag::BlackFish)
    {
        mScore += 15;
        hp -= 4;
    }

    // 金魚以外を掬ったら
    if (tag == Tag::FailureFish)
    {
        hp -= 6;
    }
}

/// <summary>
/// 当たり判定
/// </summary>
void PoiBase::Coll()
{
    float pPosX = mPosX - 64.0f;
    float pPosY = mPosY;
    float mRadius = mHalfScaleX;

    CollisionInfo tmpFish;
    for (int i = 0; i < 30; i++)
    {
        tmpFish = FishManager::GetCollisionInfo(i);

        float fPosX = tmpFish.pos.x;
        float fPosY = tmpFish.pos.y;
        float fRadius = 32.0f;

        float vecX = pPosX - fPosX;
        float vecY = pPosY - fPosY;
        float vec = sqrt(vecX * vecX + vecY * vecY);

        if (vec <= fRadius + fRadius)
        {
            CalcScore(tmpFish.tag);
        }
    }
}
