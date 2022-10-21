#pragma once
#include "Math.h"
#include "Image.h"

/// <summary>
/// 画像ファイルの順番.
/// </summary>
enum ButtonImgFileNum : unsigned short
{
	NoneBtn = 0,              // ボタン画像が何もない時.
	StartBtn,                 // ボタン画像が始める時.
	ExitBtn,                  // ボタン画像が閉じる時.

	MaxBtnFileNum,            // ボタン画像の最大枚数.
};

// 上記のenumクラスの順番で画像ファイルパスを保存する変数.
const char* ButtonImgName[ButtonImgFileNum::MaxBtnFileNum] =
{
	"img/Button/None.png",    // 何もない時の画像ファイルパス.
	"img/Button/Start.png",   // 始める時の画像ファイルパス.
	"img/Button/Exit.png",    // 閉じる時の画像ファイルパス.
};

/// <summary>
/// enumClassのボタンのステータス、型はunsigned short.
/// </summary>
enum class BtnState :unsigned short
{
	None = 0,
	Start,
	Retry,
	Exit,

	MaxStateNum,
};

/// <summary>
/// ボタン画像や処理を行うクラス.
/// </summary>
class Button : public Image
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="fileName">const char*型のボタン画像のファイルパス.</param>
	Button(const char* fileName, BtnState state);

	/// <summary>
	/// デストラクタ.
	/// </summary>
	~Button();

	/// <summary>
	/// 更新関数、オーバーライド関数.
	/// </summary>
	/// <param name="deltaTime">float型のデルタタイムの引数.</param>
	void Updata(float deltaTime) override;

	/// <summary>
	/// 描画関数、オーバーライド関数.
	/// </summary>
	void Draw() override;

private:
	BtnState mState;                     // それぞれのボタンに振り分けられているステータスを保存する変数.

	bool mChangeSceneFlag;               // シーン移動フラグ、trueの時はシーンを変えてfalseの時はシーンを変えない.
	bool mGameExitFlag;                  // ゲーム終了フラグ、trueの時はゲームを終了させてfalseの時はゲームを続ける.

	// 一度キーを押したかどうかのフラグ（長押し防止用フラグ）、trueの時はキーを一度押したとしてfalseの時はキーを押していないとする.
	bool mPushBtnFlag; 

public:// ------------------セッター・ゲッター関数-------------------------

	/// <summary>
	/// 現在のシーンを変えるフラグを取得する関数.
	/// </summary>
	/// <returns>bool型のシーン移動フラグを返す.</returns>
	bool GetChangeSceneFlag() { return mChangeSceneFlag; }
};