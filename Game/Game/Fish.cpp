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
	,mSinWaveX(0.0f)
	,mXerr(0.0f)
	,mYerr(0.0f)
	,mSinWaveAngle(0.0f)
	,mSpeed(10.0f)
    ,mIsSwim(false)
{
	mAngle = 45;
}

Fish::~Fish()
{
}

void Fish::Init()
{
	// 座標を最小値から最大値の間でランダムに初期化
	int randPosX = mMinPosX + rand() % (mMaxPosX - mMinPosX + 1);
	int randPosY = mMinPosX + rand() % (mMaxPosY - mMinPosY + 1);
	mPosition.x = randPosX;
	mPosition.y = randPosY;

	// アクティブ状態にセット
	mNowState = State::Active;
}

void Fish::MoveSinWave()
{
	float delx = mSpeed * std::cos(mAngle - Math::PiOver2) + mXerr;
	float dely = mSpeed * std::sin(mAngle - Math::PiOver2) + mYerr;
	
	mPosition.x += std::lround(delx);
	mPosition.y += std::lround(dely);
	
	mXerr = delx - std::lround(delx);
	mYerr = delx - std::lround(dely);

	if (mSinWaveX == 0.0f)
	{
		mSinWaveAngle = mAngle;
	}

	// 傾きを算出
	float slope = -mAmplitude * (2.0 * Math::Pi / mWwaveLength) *
		          std::sin((2.0 * Math::Pi / mWwaveLength) * mSinWaveX);

	mSinWaveX += mSpeed / (Math::Sqrt(slope * slope + 1));
	mAngle = mSinWaveAngle + std::atan(slope);
}

void Fish::SetMovement(float paramerter1, float parameter2,float angle)
{
	mAmplitude = paramerter1;
	mWwaveLength = parameter2;
	mAngle = angle;
}

bool Fish::OverLimitPos()
{
	// 制限された座標を超えていたら
	if (mWindowLeftUpPos.x > mPosition.x ||
		mWindowRightDownPos.x < mPosition.x ||
		mWindowLeftUpPos.y > mPosition.y ||
		mWindowRightDownPos.y < mPosition.y)
	{
		return true;
	}

	return false;
}
