#include "Title.h"

/// <summary>
/// コンストラクタ.
/// </summary>
Title::Title()
{
}

/// <summary>
/// デストラクタ.
/// </summary>
Title::~Title()
{
}

/// <summary>
/// 更新関数.
/// </summary>
/// <param name="deltaTime">float型のデルタタイムの引数.</param>
/// <returns>SCENE_TAG型のenumクラスを返す.</returns>
SCENE_TAG Title::Update(float deltaTime)
{
	// Backgroundクラスの更新関数を行う.
	mBg->Update();

	// ボタンが押されたときにプレイシーンへ移行する処理@@@

	// それ以外の場合はこのシーンを返す.
	return SCENE_TAG::NONE_TAG;
}

/// <summary>
/// 描画関数.
/// </summary>
void Title::Draw()
{
	// タイトルシーンの背景を描画.
	mBg->Draw();
}