#pragma once
#include "SceneBase.h"

/// <summary>
/// シーンのプレイクラス.
/// SceneBaseを継承している.
/// </summary>
class Play : public SceneBase
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	Play();

	/// <summary>
	/// デストラクタ.
	/// </summary>
	~Play();

	/// <summary>
	/// 更新関数、オーバーライド関数.
	/// </summary>
	/// <param name="deltaTime">float型のデルタタイム.</param>
	/// <returns>SceneTag型のenumクラスを返す.</returns>
	SceneTag Updata(float deltaTime) override;

	/// <summary>
	/// 描画関数、オーバーライド関数.
	/// </summary>
	void Draw() override;

	/// <summary>
	/// 入力処理関数、オーバーライド関数.
	/// </summary>
	void Input() override;

private:
};