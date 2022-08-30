#include "Background.h"
#include <DxLib.h>

/// <summary>
/// コンストラクタ.
/// </summary>
Background::Background(const char* fileName)
	:mPos(Vector2::Zero)
	,mScale(Vector2::Zero)
	,mImgHandle(-1)
{
	// 画像ハンドルの取得.
	mImgHandle = LoadGraph(fileName);

	// 画像の大きさの取得.
	GetGraphSizeF(mImgHandle, &mScale.x, &mScale.y);
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