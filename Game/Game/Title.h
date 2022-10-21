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
	/// <param name="deltaTime">float型のデルタタイムの引数.</param>
	/// <returns>SceneTag型のenumクラスを返す.</returns>
	SceneTag Updata() override;

	/// <summary>
	/// 描画処理、オーバーライド関数.
	/// </summary>
	void Draw() override;

	/// <summary>
	/// 入力処理関数、オーバーライド関数.
	/// </summary>
	SceneTag Input() override;

private:
	/// <summary>
	/// ボタンのステータス.
	/// 入っている値の型はunsigned short.
	/// </summary>
	enum class btnState : unsigned short
	{
		Start = 1,                   // Joypadがスタートボタンをオンマウス状態にあるとき.
		Exit,                        // Joypadがとじるボタンをオンマウス状態にあるとき.
	};

	Button* mStartBtn;               // チュートリアルに移行するButtonクラスの変数.
	Button* mExitBtn;                // ゲームを閉じるButtonクラスの変数.
	btnState mNowBtnState;           // 今Joypadがオンマウス状態にあるステータスの値を保存する変数.
};