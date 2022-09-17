#include "Poi.h"
#include "Dxlib.h"

/// <summary>
/// コンストラクタ
/// </summary>
Poi::Poi(const int num)
	:mImage(0)
	,mPositionX(0)
	,mPositionY(0)
	,mScaleX(128.0f)
	,mScaleY(256.0f)
	,mScale(1.0f)
	,mPadNum(0)
	,mInputX(0)
	,mInputY(0)
	,mSpeed(400.0f)
	,mAnimCounter(0)
	,mAnimNum(0)
	,mPoiHP(24)
{
	const char* scoopImgStr = NULL;
	const char* breakImgStr = NULL;
	if (num == 1)
	{
		scoopImgStr = "data/PlayerScoop.png";
		breakImgStr = "data/PlayerBreak.png";
		mPositionX = 480;
		mPositionY = 810;
		mPadNum = DX_INPUT_PAD1;
	}
	else if (num == 2)
	{
		scoopImgStr = "data/PlayerScoop2.png";
		breakImgStr = "data/PlayerBreak2,png";
		mPositionX = 1440;
		mPositionY = 810;
		mPadNum = DX_INPUT_PAD2;
	}

	LoadDivGraph(scoopImgStr, 5, 5, 1, (int)mScaleX, (int)mScaleY, mScoopImg);
	LoadDivGraph(breakImgStr, 5, 5, 1, (int)mScaleX, (int)mScaleY, mBreakImg);
	mHalfScaleX = mScaleX / 2.0f;
	mHalfScaleY = mScaleY / 2.0f;
	mIsBonus      = false;
	mIsScoop      = false;
	mIsFirstFrame = false;
	mPrevInputA   = false;
	
}

/// <summary>
/// デストラクタ
/// </summary>
Poi::~Poi()
{
}

/// <summary>
/// オブジェクトの更新処理
/// </summary>
/// <param name="deltaTime">1フレームの経過時間</param>
void Poi::UpdateObject(float deltaTime)
{
	// 移動
	Move(deltaTime);

	// 位置調整
	AdjustPosition();

	// ボーナス
	BonusTime(deltaTime);

	// 掬う
	Scoop(deltaTime);

	// 体力確認
	CheckHP();
}

/// <summary>
/// 描画処理
/// </summary>
void Poi::Draw()
{
	DrawRotaGraph((int)mPositionX, (int)mPositionY, mScale, 0, mImage, TRUE);
}

/// <summary>
/// 移動処理
/// </summary>
/// <param name="deltaTime">1フレームの経過時間</param>
void Poi::Move(float deltaTime)
{
	// スティックの入力状態を取得
	GetJoypadAnalogInput(&mInputX, &mInputY, mPadNum);

	// 右に倒れていたら
	if (mInputX > 0)
	{
		mPositionX += mSpeed * deltaTime;
	}

	// 左に倒れていたら
	if (mInputX < 0)
	{
		mPositionX -= mSpeed * deltaTime;
	}

	// 上に倒れていたら
	if (mInputY > 0)
	{
		mPositionY += mSpeed * deltaTime;
	}

	// 下に倒れていたら
	if (mInputY < 0)
	{
		mPositionY -= mSpeed * deltaTime;
	}
}

/// <summary>
/// 位置調整処理
/// </summary>
void Poi::AdjustPosition()
{
	if (mPositionX - (mHalfScaleX * mScale) <= 0)
	{
		mPositionX = (mHalfScaleX * mScale);
	}

	if (mPositionX + (mHalfScaleX * mScale) >= 1920)
	{
		mPositionX = 1920 - (mHalfScaleX * mScale);
	}

	if (mPositionY - (mHalfScaleY * mScale) <= 0)
	{
		mPositionY = (mHalfScaleY * mScale);
	}

	if (mPositionY >= 1080)
	{
		mPositionY = 1080;
	}
}

/// <summary>
/// ボーナスタイム処理
/// </summary>
/// <param name="deltaTime">1フレームの経過時間</param>
void Poi::BonusTime(float deltaTime)
{
	if (mIsBonus)
	{
		mScale = 2.0f;
		//mBonusCounter+=deltaTime;
	}
	else
	{
		mScale = 1.0f;
	}

	/*if (mBonusCounter > 5.0f)
	{
		mBonusCounter = 0;
	}*/
}

/// <summary>
/// 掬う処理
/// </summary>
/// <param name="deltaTime">1フレームの経過時間</param>
void Poi::Scoop(float deltaTime)
{
	if ((GetJoypadInputState(mPadNum) & PAD_INPUT_3) == 0)
	{
		mPrevInputA = FALSE;
	}
	else
	{
		if (!mPrevInputA)
		{
			if (!mIsScoop)
			{
				mIsScoop = TRUE;
				mIsFirstFrame = TRUE;
			}
			mPrevInputA = TRUE;
		}
	}

	if (mIsScoop)
	{
		if (mIsFirstFrame)
		{
			mAnimCounter = 0;
			mIsFirstFrame = FALSE;
		}
		mAnimNum = int(mAnimCounter * 8);
		mImage = mScoopImg[mAnimNum];
		if (mAnimNum >= 4)
		{
			mIsScoop = FALSE;
		}
	}
	else
	{
		mIsFirstFrame = TRUE;
	}
}

/// <summary>
/// 体力確認処理
/// </summary>
void Poi::CheckHP()
{
	if (!mIsScoop)
	{
		if (mPoiHP < 1)
		{
			mImage = mBreakImg[4];
		}
		else if (mPoiHP >= 1 && mPoiHP < 8)
		{
			mImage = mBreakImg[3];
		}
		else if (mPoiHP >= 8 && mPoiHP < 16)
		{
			mImage = mBreakImg[2];
		}
		else if (mPoiHP >= 16 && mPoiHP < 24)
		{
			mImage = mBreakImg[1];
		}
		else if (mPoiHP == 24)
		{
			mImage = mBreakImg[0];
		}
	}
}
