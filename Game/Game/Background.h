#pragma once
#include "Math.h"

/// <summary>
/// 画像ファイルの順番.
/// </summary>
enum BgImgFileNum : unsigned short
{
	NoneBg = 0,      // 背景が何もない時.
	TitleBg,         // 背景がタイトルの時.
	TutorialBg,      // 背景がチュートリアル
	PlayBg,          // 背景がプレイの時.
	ResultBg,        // 背景がリザルトの時.

	MaxBgNum,        // 背景画像の最大枚数.
};

// 上記のenumクラスの順番で画像パスを保存する保存変数.
static const char* BgImgName[BgImgFileNum::MaxBgNum] =
{
	"Img/Bg/none.png",       // 何もない時の画像ファイルパス.
	"Img/Bg/Title.png",      // タイトル時の画像ファイルパス.
	"Img/Bg/Tutorial.png",   // チュートリアル時の画像ファイルパス.
	"Img/Bg/Play.png",       // プレイ時の画像ファイルパス.
	"Img/Bg/Result.png",     // リザルト時の画像ファイルパス.
};

/// <summary>
/// 背景クラス.
/// </summary>
class Background
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	Background(const char* fileName);

	/// <summary>
	/// デストラクタ.
	/// </summary>
	~Background();

	/// <summary>
	/// 更新関数.
	/// </summary>
	void Update();

	/// <summary>
	/// 描画関数.
	/// </summary>
	void Draw();

private:
	Vector2 mPos;               // 座標保存変数.
	Vector2 mScale;             // 画像の大きさの保存変数.
	int mImgHandle;             // 画像ハンドル保存変数.

public:// ---------セッター・ゲッター関数--------------
	
	/// <summary>
	/// 背景画像の座標を設定する関数.
	/// </summary>
	/// <param name="pos">Vector2型のpos.</param>
	void SetPosition(Vector2 pos)
	{
		mPos = pos;
	}

	/// <summary>
	/// 現在の座標を返す.
	/// </summary>
	/// <returns>Vector2型の変数を返す.</returns>
	Vector2 GetPosition()
	{
		return mPos;
	}

	/// <summary>
	/// 現在の画像サイズを返す.
	/// </summary>
	/// <returns>Vector2型の変数を返す.</returns>
	Vector2 GetScale()
	{
		return mScale;
	}
};