#pragma once
#include "SceneBase.h"
#include "Button.h"

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
	Button* mTitleBtn;            // タイトルに移行するButtonクラスの変数.
	Button* mExitBtn;             // ゲームを閉じるButtonクラスの変数.

	BtnState mNowOnBtn;           // 現在オンマウス状態にあるボタンのステータスを取得する.
};