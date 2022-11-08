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
	// ���W���ŏ��l����ő�l�̊ԂŃ����_���ɏ�����
	int randPosX = mMinPosX + rand() % (mMaxPosX - mMinPosX + 1);
	int randPosY = mMinPosX + rand() % (mMaxPosY - mMinPosY + 1);
	mPosition.x = randPosX;
	mPosition.y = randPosY;

	// �A�N�e�B�u��ԂɃZ�b�g
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

	// �X�����Z�o
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
	// �������ꂽ���W�𒴂��Ă�����
	if (mWindowLeftUpPos.x > mPosition.x ||
		mWindowRightDownPos.x < mPosition.x ||
		mWindowLeftUpPos.y > mPosition.y ||
		mWindowRightDownPos.y < mPosition.y)
	{
		return true;
	}

	return false;
}
