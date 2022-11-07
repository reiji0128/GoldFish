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
	TutorialSkip,             // ボタン画像がチュートリアルをスキップの時.
	TitleBtn,                 // ボタン画像がタイトルの時.

	MaxBtnFileNum,            // ボタン画像の最大枚数.
};

// 上記のenumクラスの順番で画像ファイルパスを保存する変数.
static const char* ButtonImgName[ButtonImgFileNum::MaxBtnFileNum] =
{
	"img/None.png",                     // 何もない時の画像ファイルパス.
	"img/Button/Start.png",             // 始める時の画像ファイルパス.
	"img/Button/Exit.png",              // 閉じる時の画像ファイルパス.
	"img/Button/TutorialSkip2.png",     // スキップの画像ファイルパス.
	"img/Button/Title.png",             // タイトルの画像ファイルパス.
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
	TutoSkip,                 // オンマウスした画像がチュートリアルをスキップする時.
	Title,                    // オンマウスした画像がタイトルの時.

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
	void Updata(float deltaTime, ViewState state) override;

private:
	BtnState mState;                     // それぞれのボタンに振り分けられているステータスを保存する変数.
	float mRad;                          // 上下の動きをする際の振れ幅の大きさ(float型).
	const float M_SPEED;                 // 上下の動きのスピード(const float型).

public:// ------------------セッター・ゲッター関数-------------------------
	/// <summary>
	/// そのボタンのステータスを取得する関数.
	/// </summary>
	/// <returns>BtnStateクラスの変数.</returns>
	BtnState GetBtnState() { return mState; }
};