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
	/// 更新処理、オーバーライド関数.
	/// </summary>
	/// <returns>SceneBaseのenumClassであるSceneTag型を返す.</returns>
	SceneTag Update() override;

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