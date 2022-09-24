#pragma once
#include "FishStateBase.h"
#include "Fish.h"

class FishStateTurn : public FishStaeBase
{
public:
	FishStateTurn();

	~FishStateTurn();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="owner">プレイヤーのポインタ</param>
	/// <param name="deltaTime">1フレームの経過時間</param>
	/// <returns>プレイヤーの状態</returns>
	FishState Update(Fish* owner, float deltaTime) override;

	/// <summary>
	/// 状態が移行したときに1度だけする処理
	/// </summary>
	/// <param name="owner">プレイヤーのポインタ</param>
	/// <param name="deltaTime">1フレームの経過時間</param>
	void Enter(Fish* owner, float deltaTime) override;
};