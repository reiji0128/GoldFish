#pragma once
#include "Math.h"

/// <summary>
/// 画像ファイルの順番.
/// </summary>
static enum BackgroundFileNum
{
	NONE_IMG = 0,
	TITLE_IMG,
	PLAY_IMG,
	RESULT_IMG,

	MAX_IMG_FILE_NUM,
};

static const char* MapPicName[MAX_IMG_FILE_NUM] =
{
	"img/none.png",
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
	/// 画像の横幅の取得関数.
	/// </summary>
	/// <returns>int型の画像の横幅.</returns>
	int GetImgWidth()
	{
		return mWidth;
	}

	/// <summary>
	/// 画像の縦幅の取得関数.
	/// </summary>
	/// <returns>int型の画像の縦幅.</returns>
	int GetImgHeight()
	{
		return mHeight;
	}
};