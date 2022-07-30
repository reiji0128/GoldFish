#pragma once
#include "SceneBase.h"

/// <summary>
/// シーンのタイトルクラス.
/// SceneBaseを継承している.
/// </summary>
class Title : public SceneBase
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	Title();

	/// <summary>
	/// デストラクタ.
	/// </summary>
	~Title();


	SCENE_TAG Update(float deltaTime) override;

	/// <summary>
	/// 描画関数.
	/// オーバーライド関数.
	/// </summary>
	void Draw() override;

private:
};