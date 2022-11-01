#pragma once
#include "BaseObject.h"
#include <vector>

class FishStateBase;

enum class State
{
	Active,
	Inacive
};

class Fish : public BaseObject
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="tag">1フレームの経過時間</param>
	Fish(Tag tag);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Fish();

	void Init();

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw() {};

	/// <summary>
	/// 止まっている処理
	/// </summary>
	void StopProces();

	// 正弦波の動き
	void MoveSinWave();

// セッター //

	void SetMovement(float paramerter1, float parameter2,float angle);

// ゲッター　//

	/// <summary>
	/// 現在の状態の取得
	/// </summary>
	/// <returns>現在の状態</returns>
	State const GetState() { return mNowState; }

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

	// 正弦波のX
	float mSinWaveX;
	// 正弦波の角度
	float mSinWaveAngle;
	// 振幅
	float mAmplitude;
	// 波長
	float mWwaveLength;

	// スピード
	float mSpeed;
	float mXerr;
	float mYerr;

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

	const Vector2 mWindowLeftUpPos = Vector2(0, 0);
	const Vector2 mWindowRightDownPos = Vector2(1920, 1080);

	// 現在の状態
	State mNowState;
};
