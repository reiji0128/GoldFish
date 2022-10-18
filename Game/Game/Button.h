#pragma once
#include "Math.h"
#include "ImageBase.h"

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
/// ボタン画像や処理を行うクラス.
/// </summary>
class Button : public ImageBase
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="fileName">const char*型のボタン画像のファイルパス.</param>
	Button(const char* fileName);

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
};