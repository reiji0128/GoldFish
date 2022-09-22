#include "Play.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ.
/// </summary>
Play::Play()
	:SceneBase(SceneBase::SceneTag::PLAY_TAG)
{
}

/// <summary>
/// デストラクタ.
/// </summary>
Play::~Play()
{
}

/// <summary>
/// 更新関数.
/// </summary>
/// <param name="deltaTime">float型のデルタタイムの引数.</param>
/// <returns>SCENE_TAG型のenumクラスを返す.</returns>
SceneBase::SceneTag Play::Update()
{
	//mBg->Update();

	//gameManager->Update(deltaTime);

	// 特定の条件でリザルトシーンを移行する処理
	if (mChangeSceneFlag)
	{
		return SceneTag::RESULT_TAG;
	}

	// それ以外の場合はこのシーンを返す.
	return SceneTag::NONE_TAG;
}

/// <summary>
/// 描画関数.
/// </summary>
void Play::Draw()
{
	mBg->Draw();
}

void Play::Input()
{
	// ここにシーンを変える条件でmChangeSceneFlagを変える.
}