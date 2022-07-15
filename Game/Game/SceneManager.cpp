#include "SceneManager.h"

/// <summary>
/// コンストラクタ.
/// </summary>
SceneManager::SceneManager()
{
	// シーンを生成.
	CreatsScene(SCENE_TAG::TITLE_TAG);

	/// <summary>
	/// ゲームループに移行.
	/// </summary>
	GameRoop();
}

/// <summary>
/// デストラクタ.
/// </summary>
SceneManager::~SceneManager()
{
}

/// <summary>
/// ゲームループ関数.
/// </summary>
void SceneManager::GameRoop()
{
	// エスケープキーが押されない間、whileをまわす.
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		if (ProcessMessage())
		{
			break;
		}
	}
}

void SceneManager::CreatsScene(SCENE_TAG sceneTag)
{
}

void SceneManager::ClearScene()
{
}
