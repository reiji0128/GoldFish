#include "Play.h"

/// <summary>
/// コンストラクタ.
/// </summary>
Play::Play()
	:gameManager(nullptr)// gameManagerの初期化.
{
	// gameManagerのコンストラクタ.
	gameManager = new GameManager();
}

/// <summary>
/// デストラクタ.
/// </summary>
Play::~Play()
{
	delete gameManager;
}

/// <summary>
/// 更新関数.
/// </summary>
/// <param name="deltaTime">float型のデルタタイムの引数.</param>
/// <returns>SCENE_TAG型のenumクラスを返す.</returns>
SCENE_TAG Play::Update(float deltaTime)
{
	//gameManager->Update();

	// 特定の条件でリザルトシーンを移行する処理@@@

	// それ以外の場合はこのシーンを返す.
	return SCENE_TAG::NONE_TAG;
}

/// <summary>
/// 描画関数.
/// </summary>
void Play::Draw()
{
}