#pragma once
#include "Math.h"

/// <summary>
/// 画像ファイルの順番.
/// </summary>
enum BgImgFileNum : unsigned short
{
	NoneBg = 0,
	TitleBg,
	PlayBg,
	ResultBg,

	MaxBgNum,
};

// 上記のenumクラスの順番で画像パスを保存する保存変数.
static const char* BgImgName[BgImgFileNum::MaxBgNum] =
{
	"Img/Bg/none.png",
	"Img/Bg/Title.png",
	"Img/Bg/Play.png",
	"Img/Bg/Result.png",
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