#pragma once
#include "SceneBase.h"

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
	/// 更新関数.
	/// </summary>
	/// <param name="deltaTime">float型のデルタタイムの引数.</param>
	/// <returns>SCENE_TAG型のenumクラスを返す.</returns>
	SCENE_TAG Update(float deltaTime);

	/// <summary>
	/// 描画関数.
	/// </summary>
	void Draw();

private:
};

