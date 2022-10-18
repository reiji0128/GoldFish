#include "DxLib.h"
#include "Background.h"

/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="fileName">const char*型(文字列型)のファイルパス.</param>
Background::Background(const char* fileName)
	// 座標保存変数の初期化.
	:mPos(Vector2::Zero)
	// 画像サイズ保存変数の初期化.
	,mScale(Vector2::Zero)
	// 画像ハンドル保存変数の初期化.
	,mImgHandle(-1)
{
	// 画像ハンドルを読み込む.
	mImgHandle = LoadGraph(fileName);

	// 画像ハンドルのサイズの取得.
	GetGraphSizeF(mImgHandle, &mScale.x, &mScale.y);
}

/// <summary>
/// デストラクタ.
/// </summary>
Background::~Background()
{
	// すでに画像ハンドルが-1の時はreturnを返す
	if (mImgHandle == -1)
	{
		return;
	}

	// 画像をメモリ上から削除する.
	DeleteGraph(mImgHandle);

	// 削除した後に-1を代入する.
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