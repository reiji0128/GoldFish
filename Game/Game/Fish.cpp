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
	//���ݎ������擾
	mNowTime = GetNowCount() / 1000;
	// �o�ߎ��Ԃ��v�Z 
	mElapsedTime= (mNowTime - mStartTime);

	// �o�ߎ��Ԃ��T�b�ȉ��Ȃ�~�܂�
	// �T�b�o�߂�����ق��̃X�e�[�g�Ɉڍs
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
		// �X�^�[�g���Ԃ̃Z�b�g
		mStartTime = GetNowCount() / 1000;
		mIsSwim = true;
	}
	//���ݎ������擾
	mNowTime = GetNowCount() / 1000;
	// �o�ߎ��Ԃ��v�Z 
	mElapsedTime = (mNowTime - mStartTime);
	//mTime = rand() % 5;
	if (mElapsedTime < mElapsedSecond)
	{
		// �摜�̉�]�p����ړ��ʂ��v�Z
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
