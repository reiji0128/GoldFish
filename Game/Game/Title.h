#pragma once
#include "SceneBase.h"
#include "Background.h"
#include "Button.h"

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

	/// <summary>
	/// 更新関数、オーバーライド関数.
	/// </summary>
	/// <param name="deltaTime">float型のデルタタイムの引数.</param>
	/// <returns>SCENE_TAG型のenumクラスを返す.</returns>
	SceneTag Update() override;

	/// <summary>
	/// 描画処理.
	/// </summary>
	void Draw() override;

	/// <summary>
	/// 入力処理関数、オーバーライド関数.
	/// </summary>
	void Input() override;

private:
	Button* mStartButton;
	Button* mExitButton;

	bool mStartFlag;
};