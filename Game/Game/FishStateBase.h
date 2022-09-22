#pragma once

class Fish;

class FishStaeBase
{
public:

	FishStaeBase() {};

	~FishStaeBase() {};


	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="owner">プレイヤーのポインタ</param>
	/// <param name="deltaTime">1フレームの経過時間</param>
	/// <returns>プレイヤーの状態</returns>
	virtual FishState Update(Fish* owner, float deltaTime) = 0;

	/// <summary>
	/// 状態が移行したときに1度だけする処理
	/// </summary>
	/// <param name="owner">プレイヤーのポインタ</param>
	/// <param name="deltaTime">1フレームの経過時間</param>
	virtual void Enter(Fish* owner, float deltaTime) {};

};