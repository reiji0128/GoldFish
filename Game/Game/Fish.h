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

	/// <summary>
	/// 止まっている処理
	/// </summary>
	void StopProces();

	/// <summary>
	/// 泳ぐ処理
	/// </summary>
	void SwimProces();

	/// <summary>
	/// 曲がる処理
	/// </summary>
	void TurnProces();

protected:

	/// <summary>
	/// 制限された座標を超えたか調べる関数
	/// </summary>
	/// <returns>
	/// true  : 制限された座標を超えた
	/// false : 制限された座標を超えていない
	/// </returns>
	bool OverLimitPos();

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
	// 目標時間(秒)
	const int mTargetTime = 2;
	// 目標角度
	int mTargetAngle;
	// 泳いでる状態か
	bool mIsSwim;
	// 座標の最小値(画面から出ないように0より大きい値)
	const int mMinPosX = 100;
	const int mMinPosY = 100;
	// 座標の最大値(画面から出ないようにフルスクリーンのサイズより小さい値)
	const int mMaxPosX = 1900;
	const int mMaxPosY = 1750;
	// 現在の状態
	FishState mNowState;
};
