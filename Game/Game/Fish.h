#pragma once
#include "BaseObject.h"
#include <vector>

class FishStateBase;

enum class FishState
{
	Stop,
	Swim,
	Turn
};

class Fish : public BaseObject
{
public:
	Fish(Tag tag);
	~Fish();

	void StopProces();
	void SwimProces();
	void TurnProces();
protected:
	// アニメーショングラフハンドル
	int mGraphHandle[8];
	// 開始時のタイム
	int mStartTime;
	// 現在のタイム
	int mNowTime;
	// 経過時間
	int mElapsedTime;
	// 現在のカウント
	int mNowCount;
	// アニメーションカウント
	int mAnimationCount;
	// ステートの番号
	int mStateNumber;
	// 経過時間(秒)
	const int mElapsedSecond = 2;
	// 目標角度
	const int mTargetAngle = 45;
	// 泳いでる状態か
	bool mIsSwim;
	// 現在の状態
	FishState mNowState;
};
