#include "Background.h"
#include <DxLib.h>

/// <summary>
/// コンストラクタ.
/// </summary>
Background::Background()
	:mPos(Vector2::Zero)
	,mWidth(0)
	,mHeight(0)
	,mImgHandle(-1)
{
}

/// <summary>
/// デストラクタ.
/// </summary>
Background::~Background()
{
	// 既に画像ハンドルが-1の時はreturnを返す.
	if (mImgHandle == -1)
	{
		return;
	}
	// 画像をメモリ上から削除する.
	DeleteGraph(mImgHandle);
	// 削除した後に-1を入力しておく.
	mImgHandle = -1;
}

/// <summary>
/// 読み込み関数.
/// </summary>
/// <param name="imgName">char*型の画像のファイルパス.</param>
void Background::Load(const char* imgName)
{
	// 画像読み込み.
	mImgHandle = LoadGraph(imgName);

	// 画像サイズの取得.
	GetGraphSize(mImgHandle, &mWidth, &mHeight);
}

/// <summary>
/// 更新関数.
/// </summary>
void Background::Update()
{
}

/// <summary>
/// 描画関数.
/// </summary>
void Background::Draw()
{
	// 描画処理.
	DrawGraph(mPos.x, mPos.y, mImgHandle, true);
}