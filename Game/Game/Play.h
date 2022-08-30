#pragma once
#include "SceneBase.h"
#include "GameManager.h"

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
	/// <param name="deltaTime">float型のデルタタイムの引数.</param>
	/// <returns>SCENE_TAG型のenumクラスをreturnとして返す.</returns>
	SCENE_TAG Update(float deltaTime) override;

	/// <summary>
	/// 描画関数、オーバーライド関数.
	/// </summary>
	void Draw() override;

private:
	/// <summary>
	/// ゲーム全体の処理が入っている変数.
	/// </summary>
	GameManager* gameManager;
};