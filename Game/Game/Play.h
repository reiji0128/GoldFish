#pragma once
#include "SceneBase.h"
//#include "Background.h"
//#include "GameManager.h"

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
	SceneTag Update() override;

	/// <summary>
	/// 描画関数.
	/// </summary>
	void Draw() override;

	/// <summary>
	/// 入力処理関数、オーバーライド関数.
	/// </summary>
	void Input() override;

private:
	///// <summary>
	///// ゲーム全体の処理が入っている変数.
	///// </summary>
	//GameManager* mGameManager;

	//bool mResultFlag;
};