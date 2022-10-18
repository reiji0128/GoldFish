#pragma once
#include "SceneBase.h"
#include "Background.h"

/// <summary>
/// シーンのリザルトクラス.
/// SceneBaseを継承している.
/// </summary>
class Result :public SceneBase
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	Result();

	/// <summary>
	/// デストラクタ.
	/// </summary>
	~Result();

	/// <summary>
	/// 更新関数、オーバーライド関数.
	/// </summary>
	/// <param name="deltaTime">float型のデルタタイムの引数.</param>
	/// <returns>SCENE_TAG型のenumクラスを返す.</returns>
	SceneTag Updata() override;

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

