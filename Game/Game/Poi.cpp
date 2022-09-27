#include "Poi.h"
#include "Dxlib.h"
#include "FishManager.h"
#include <math.h>

/// <summary>
/// コンストラクタ
/// </summary>
Poi::Poi(const int num)
	:mImage(0)
	,mFloatScale(1.0f)
	,mPadNum(0)
	,mInputX(0)
	,mInputY(0)
	,mSpeed(400.0f)
	,mAnimCounter(0)
	,mAnimNum(0)
	,mBonusCount(0)
	,mBonusCounter(0)
	,mPoiHP(24)
	,deadTime(0)
	,mScore(0)
{
	const char* scoopImgStr = NULL;
	const char* breakImgStr = NULL;
	if (num == 1)
	{
		scoopImgStr = "Img/Player/Scoop.png";
		breakImgStr = "Img/Player/Break.png";
		mPositionX = 480.0f;
		mPositionY = 810.0f;
		mPadNum = DX_INPUT_PAD1;
	}
	else if (num == 2)
	{
		scoopImgStr = "Img/Player/Scoop2.png";
		breakImgStr = "Img/Player/Break2,png";
		mPositionX = 1440.0f;
		mPositionY = 810.0f;
		mPadNum = DX_INPUT_PAD2;
	}

	mScaleX    = 128.0f;
	mScaleY    = 256.0f;
	mHalfScaleX = mScaleX / 2.0f;
	mHalfScaleY = mScaleY / 2.0f;
	mIsBonus      = false;
	mIsScoop      = false;
	mIsFirstFrame = false;
	mPrevInputA   = false;
	mAlive = true;
	LoadDivGraph(scoopImgStr, 5, 5, 1, (int)mScaleX, (int)mScaleY, mScoopImg);
	LoadDivGraph(breakImgStr, 5, 5, 1, (int)mScaleX, (int)mScaleY, mBreakImg);
	
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
void Poi::Update(float deltaTime)
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

	// ポイの修理
	PoiRepair(deltaTime);

}

/// <summary>
/// 描画処理
/// </summary>
void Poi::Draw()
{
	DrawRotaGraph((int)mPositionX, (int)mPositionY, mFloatScale, 0, mImage, TRUE);
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
	if (mPositionX - (mHalfScaleX * mFloatScale) <= 0)
	{
		mPositionX = (mHalfScaleX * mFloatScale);
	}

	if (mPositionX + (mHalfScaleX * mFloatScale) >= 1920)
	{
		mPositionX = 1920 - (mHalfScaleX * mFloatScale);
	}

	if (mPositionY - (mHalfScaleY * mFloatScale) <= 0)
	{
		mPositionY = (mHalfScaleY * mFloatScale);
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
		mBonusCounter+=deltaTime;
	}
	else
	{
		mFloatScale = 1.0f;
	}

	if (mBonusCounter > 5.0f)
	{
		mBonusCounter = 0;
		mBonusCount = 0;
		mIsBonus = false;
	}
}

/// <summary>
/// 掬う処理
/// </summary>
/// <param name="deltaTime">1フレームの経過時間</param>
void Poi::Scoop(float deltaTime)
{
	// ボタンが押されていなかったら
	if ((GetJoypadInputState(mPadNum) & PAD_INPUT_3) == 0)
	{
		// 前フレームで押されていないことにする
		mPrevInputA = FALSE;
	}
	else
	{
		// 前フレームで押されておらず
		// 掬っておらず
		// 生きていたら
		if (!mPrevInputA && !mIsScoop && mAlive)
		{
			// 掬っている状態にする
			mIsScoop = TRUE;
			// 掬い初めて1フレーム目
			mIsFirstFrame = TRUE;
			// 入水時の体力減少
			mPoiHP -= 3;
			// 押されていることにする
			mPrevInputA = TRUE;
		}
		if (mPoiHP > 0)
		{
			mAlive = true;
		}
		else
		{
			mAlive = false;
		}
		
	}

	// ポイが生きていて掬っているなら
	if (mAlive && mIsScoop)
	{
		// 1フレーム目なら
		if (mIsFirstFrame)
		{
			// アニメーションのカウンタ初期化
			mAnimCounter = 0;
			mIsFirstFrame = FALSE;

			// ポイと金魚の当たり判定を調べる
			Coll();

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

/// <summary>
/// スコア計算とHP処理
/// </summary>
/// <param name="tag">金魚の種類</param>
void Poi::CalcScoreAndHP(Tag tag)
{
	// 1Pが赤い金魚を掬ったら
	// 2Pが青い金魚を掬ったら
	if ((tag == Tag::RedFish && mPadNum == DX_INPUT_PAD1) ||
		(tag == Tag::BlueFish && mPadNum == DX_INPUT_PAD2))
	{
		mScore += 10;
		mPoiHP -= 3;
		mBonusCount++;
	}
	// お互いの色を掬ったら
	else if ((tag == Tag::RedFish && mPadNum == DX_INPUT_PAD2) ||
		(tag == Tag::BlueFish && mPadNum == DX_INPUT_PAD1))
	{
		mPoiHP -= 4;
	}

	// 金の金魚を掬ったら
	if (tag == Tag::GoldFish)
	{
		mScore += 20;
		mPoiHP -= 5;
	}

	// 黒の金魚を掬ったら
	if (tag == Tag::BlackFish)
	{
		mScore += 15;
		mPoiHP -= 4;
	}

	// 金魚以外を掬ったら
	if (tag == Tag::FailureFish)
	{
		mPoiHP -= 6;
	}
}

/// <summary>
/// ポイの修理
/// </summary>
/// <param name="deltaTime"></param>
void Poi::PoiRepair(float deltaTime)
{
	if (!mAlive)
	{
		deadTime += deltaTime;
	}

	if (deadTime > 3.0f)
	{
		deadTime = 0;
		mAlive = true;
		mPoiHP = 24;
	}
}

/// <summary>
/// 当たり判定
/// </summary>
void Poi::Coll()
{
	float pPosX   = mPositionX - 64.0f;
	float pPosY   = mPositionY;
	float pRadius = mHalfScaleX;


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

		if (vec <= pRadius + fRadius)
		{
			// 当たっている
			CalcScoreAndHP(tmpFish.tag);
		}
		else
		{
			// 当たっていない
		}
	}
	
}
