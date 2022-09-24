#include "Fish.h"
#include "Math.h"
#include <DxLib.h>

Fish::Fish(Tag tag)
	:BaseObject(tag)
	,mStartTime(0)
	,mNowTime(0)
	,mElapsedTime(0)
    ,mNowCount(0)
	,mAnimationCount(0)
    ,mStateNumber(0)
    ,mIsSwim(false)
{
}

Fish::~Fish()
{
}

void Fish::StopProces()
{
	//現在時刻を取得
	mNowTime = GetNowCount() / 1000;
	// 経過時間を計算 
	mElapsedTime= (mNowTime - mStartTime);

	// 経過時間が５秒以下なら止まる
	// ５秒経過したらほかのステートに移行
	if (mElapsedTime < 5)
	{
		mPosition.x += 0;
		mPosition.y += 0;
	}
	else
	{
		mStateNumber = rand() % 2;
		if (mStateNumber == 0)
		{
			mNowState = FishState::Turn;
		}
		else
		{
			mNowState = FishState::Swim;
		}
	}
}

void Fish::SwimProces()
{
	if (!mIsSwim)
	{
		// スタート時間のセット
		mStartTime = GetNowCount() / 1000;
		mIsSwim = true;
	}
	//現在時刻を取得
	mNowTime = GetNowCount() / 1000;
	// 経過時間を計算 
	mElapsedTime = (mNowTime - mStartTime);
	//mTime = rand() % 5;
	if (mElapsedTime < mElapsedSecond)
	{
		// 画像の回転角から移動量を計算
		double delx = -1 * std::cos(90 + Math::Pi / 2);
		double dely = -1 * std::sin(90 + Math::Pi / 2);
		mPosition.x += std::lround(delx);
		mPosition.y += std::lround(dely);
	}
	else
	{
		mStateNumber = rand() % 2;
		if (mStateNumber == 0)
		{
			mNowState = FishState::Stop;
		}
		else
		{
			mNowState = FishState::Turn;
		}
		mIsSwim = false;
	}
}

void Fish::TurnProces()
{
	if (mAngle < mTargetAngle)
	{
		mAngle += 1;
	}
	else
	{
		mStateNumber = rand() % 2;
		if (mStateNumber == 0)
		{
			mNowState = FishState::Stop;
		}
		else
		{
			mNowState = FishState::Swim;
		}
		mAngle = 0;
	}
}
