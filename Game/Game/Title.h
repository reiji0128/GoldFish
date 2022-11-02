#pragma once
#include "SceneBase.h"
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
	/// <param name="deltaTime">float型のデルタタイム.</param>
	/// <returns>SceneTag型のenumクラスを返す.</returns>
	SceneTag Updata(float deltaTime) override;

	/// <summary>
	/// 描画処理、オーバーライド関数.
	/// </summary>
	void Draw() override;

	/// <summary>
	/// 入力処理関数、オーバーライド関数.
	/// </summary>
	void Input() override;

private:
	Button* mStartBtn;               // チュートリアルに移行するButtonクラスの変数.
	Button* mExitBtn;                // ゲームを閉じるButtonクラスの変数.

	BtnState mNowOnBtn;              // 現在オンマウスしているボタンのステータスを取得する.
};