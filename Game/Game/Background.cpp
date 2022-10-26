#include "DxLib.h"
#include "Background.h"

/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="fileName">const char*型の画像ファイルパス.</param>
Background::Background(const char* fileName)
	:Image(fileName)
{
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
void Background::Updata(float deltaTime)
{
}