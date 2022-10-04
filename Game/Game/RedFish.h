#pragma once
#include "Fish.h"

class RedFish : public Fish
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="tag">オブジェクトのタグ</param>
	RedFish(Tag tag);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~RedFish();

	/// <summary>
	/// オブジェクトの更新処理
	/// </summary>
	/// <param name="deltaTime">1フレームの経過時間</param>
	void UpdateObject(float deltaTime) override;

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw() override;
};
