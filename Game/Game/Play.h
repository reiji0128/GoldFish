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
	/// 更新関数.
	/// オーバーライド関数.
	/// </summary>
	/// <param name="deltaTime">float型のデルタタイムを引数として設定する.</param>
	/// <returns></returns>
	SCENE_TAG Update(float deltaTime) override;
};