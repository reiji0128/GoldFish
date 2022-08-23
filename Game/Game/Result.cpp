#include "Result.h"

/// <summary>
/// コンストラクタ.
/// </summary>
Result::Result()
{
}

/// <summary>
/// デストラクタ.
/// </summary>
Result::~Result()
{
}

/// <summary>
/// 更新関数.
/// </summary>
/// <param name="deltaTime">float型のデルタタイムの引数.</param>
/// <returns>SCENE_TAG型のenumクラスを返す.</returns>
SCENE_TAG Result::Update(float deltaTime)
{
	// タイトルシーンへの移行処理.@@@

	// ゲーム終了処理.@@@

	// それ以外はこのシーンを返す.
	return SCENE_TAG::NONE_TAG;
}

/// <summary>
/// 描画関数.
/// </summary>
void Result::Draw()
{
	// 背景の描画処理.
	mBg->Draw();
}