#pragma once
#include "BaseObject.h"

/// <summary>
/// ポイクラス
/// BaseObjectを継承している
/// </summary>
class Poi : public BaseObject
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Poi(const int num);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Poi();

	/// <summary>
	/// オブジェクトの更新処理
	/// </summary>
	/// <param name="deltaTime">1フレームの経過時間</param>
	void UpdateObject(float deltaTime)override;

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

private:
	/// <summary>
	/// 移動処理
	/// </summary>
	/// <param name="deltaTime">1フレームの経過時間</param>
	void Move(float deltaTime);

	/// <summary>
	/// 位置調整処理
	/// </summary>
	void AdjustPosition();

	/// <summary>
	/// ボーナスタイム処理
	/// </summary>
	/// <param name="deltaTime">1フレームの経過時間</param>
	void BonusTime(float deltaTime);

	/// <summary>
	/// 掬う処理
	/// </summary>
	/// <param name="deltaTime">1フレームの経過時間</param>
	void Scoop(float deltaTime);

	/// <summary>
	/// 体力確認処理
	/// </summary>
	void CheckHP();

	// 座標
	float mPositionX;
	float mPositionY;

	// スケール（変動用）
	float mScale;

	// スケール
	float mScaleX;
	float mScaleY;

	// 元のスケールの半分
	float mHalfScaleX;
	float mHalfScaleY;

	// コントローラーの入力状態
	int mPadNum;
	int mInputX;
	int mInputY;

	// 速度
	float mSpeed;

	// 画像
	int mImage;

	// 破れ差分
	int mBreakImg[5];

	// 掬う差分
	int mScoopImg[3];

	// 掬っているかどうか
	bool mIsScoop;

	// 1フレーム目かどうか
	bool mIsFirstFrame;

	// 前フレームでの入力していたかどうか
	bool mPrevInputA;

	// アニメーション用
	float mAnimCounter;
	int mAnimNum;

	// ボーナス用
	bool mIsBonus;
	//float mBonusCounter;

	// ポイの耐久値
	int mPoiHP;

};