#pragma once
#include "Math.h"

/// <summary>
/// 画像ファイルの順番.
/// </summary>
static enum class ImgFileNum :short
{
	NONE_IMG = 0,
	TITLE_IMG,
	PLAY_IMG,
	RESULT_IMG,

	MAX_IMG_FILE_NUM,
};

// 上記のenumクラスから
static const char* MapPicName[] =
{
	"img/none.png",
};

/// <summary>
/// 画像クラス.
/// 
/// </summary>
class Image
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	Image(const char* fileName);

	/// <summary>
	/// デストラクタ、仮想関数.
	/// </summary>
	virtual ~Image();

	/// <summary>
	/// 更新関数、仮想関数.
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// 描画関数、仮想関数.
	/// </summary>
	virtual void Draw() = 0;

private:
	Vector2 mPos;          // 座標保存関数.
	Vector2 mScale;        // 画像サイズ保存変数.
	int     mImgHandle;    // 画像ハンドル保存変数.

public://--------------セッター・ゲッター------------------//
	
	/// <summary>
	/// 背景画像の座標を設定する関数.
	/// </summary>
	/// <param name="pos">Vector2型の座標.</param>
	void SetPosition(Vector2 pos)
	{
		mPos = pos;
	}

	/// <summary>
	/// 画像の座標を取得する関数.
	/// </summary>
	/// <returns></returns>
	Vector2 GetPosition()
	{
		return mPos;
	}

	/// <summary>
	/// 画像サイズを取得する関数.
	/// </summary>
	/// <returns>Vector2型の大きさ.</returns>
	Vector2 GetScale()
	{
		return mScale;
	}
};