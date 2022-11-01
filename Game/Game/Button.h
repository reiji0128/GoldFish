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
static const char* ButtonImgName[ButtonImgFileNum::MaxBtnFileNum] =
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
	None = 0,                 // オンマウスした画像が何もない時.
	Start,                    // オンマウスした画像がスタートの時.
	Retry,                    // オンマウスした画像がリトライの時.
	Exit,                     // オンマウスした画像がゲーム終了の時.

	MaxStateNum,              // ボタンステータスの最大数.
};

/// <summary>
/// ボタン処理を行うクラス.
/// Imageクラスを継承.
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

	///// <summary>
	///// 入力処理関数.
	///// </summary>
	//void Input(BtnState state);

	/// <summary>
	/// 描画関数、オーバーライド関数.
	/// </summary>
	void Draw() override;

private:
	BtnState mState;                     // それぞれのボタンに振り分けられているステータスを保存する変数.

	//// 一度キーを押したかどうかのフラグ（長押し防止用フラグ）、trueの時はキーを一度押したとしてfalseの時はキーを押していないとする.
	//bool mPushedBtnFlag; 

public:// ------------------セッター・ゲッター関数-------------------------
	/// <summary>
	/// そのボタンのステータスを取得する関数.
	/// </summary>
	/// <returns>BtnStateクラスの変数.</returns>
	BtnState GetBtnState() { return mState; }

	///// <summary>
	///// ボタンが押されているかどうかのフラグを設定する関数.
	///// </summary>
	///// <param name="flag">設定するbool型変数または真偽値.</param>
	//void SetPushedBtnFlag(bool flag) { mPushedBtnFlag = flag; }

	///// <summary>
	///// ボタンが押されているかどうかのフラグを取得する関数.
	///// </summary>
	///// <returns>現在そのボタンが押されているときはtrue、押されていないときはfalseを返す.</returns>
	//bool GetPushedBtnFlag() { return mPushedBtnFlag; }
};