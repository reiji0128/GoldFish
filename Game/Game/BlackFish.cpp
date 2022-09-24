#include "BlackFish.h"
#include <DxLib.h>

BlackFish::BlackFish(Tag tag)
	:Fish(tag)
{
	LoadDivGraph("Assets/GoldFish/GoldFish_Black.png", 8, 8, 1, 128, 128, mGraphHandle);
	mStateNumber = rand() % 2;

	if (mStateNumber == 0)
	{
		mNowState = FishState::Stop;
	}
	else
	{
		mNowState = FishState::Swim;
	}

	// ŠJŽnŽž‚ÌŽžŠÔ‚ðŽæ“¾
	mStartTime = GetNowCount() / 1000;
}

BlackFish::~BlackFish()
{
}

void BlackFish::UpdateObject(float deltaTime)
{
	switch (mNowState)
	{
	case FishState::Stop:
		StopProces();
		break;

	case FishState::Swim:
		SwimProces();
		break;

	case FishState::Turn:
		TurnProces();
		break;
	}
}

void BlackFish::Draw()
{
	mNowCount = GetNowCount();
	mAnimationCount = mNowCount / 120 % 8;

	DrawRotaGraph(mPosition.x, mPosition.y, 1.0, mAngle * (Math::Pi / 180), mGraphHandle[mAnimationCount], true);
}
