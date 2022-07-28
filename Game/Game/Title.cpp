#include "Title.h"

Title::Title()
{
}

Title::~Title()
{
}

SCENE_TAG Title::Update(float deltaTime)
{
	mBg->Update();

	// ここでボタンが押されたときにプレイシーンへ移行する処理@@@

	// それ以外の場合はこのシーンを返す.
	return SCENE_TAG::NONE_TAG;
}

void Title::Draw()
{
	// タイトルの背景を描画.
	mBg->Draw();
}