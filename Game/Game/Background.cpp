#include "Background.h"

/// <summary>
/// コンストラクタ.
/// </summary>
Background::Background()
{
}

/// <summary>
/// デストラクタ.
/// </summary>
Background::~Background()
{
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