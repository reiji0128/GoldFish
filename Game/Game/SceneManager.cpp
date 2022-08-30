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
		// ウィンドウのメッセージがエラーを出したときゲームループを終了する.
		if (ProcessMessage())
		{
			break;
		}

		//// 現在のシーンタグを保存する.@@@
		//SCENE_TAG tag = mNowScene->Update();

		// ------------描画処理-------------- //
		ClearDrawScreen();

		// 現在のシーンを描画.
		mNowScene->Draw();

		ScreenFlip();

		//// シーンタグが無しの時は以下の処理は実行しない.@@@
		//if (tag == SCENE_TAG::NONE_TAG)
		//{
		//	continue;
		//}

		// シーンの削除.@@@
		ClearScene();

		//// シーンの生成.@@@
		//CreatsScene(tag);
	}
}

/// <summary>
/// シーンの生成関数.
/// </summary>
/// <param name="sceneTag">次のシーンを保存するenum class型変数.</param>
void SceneManager::CreatsScene(SCENE_TAG sceneTag)
{
	if (sceneTag == SCENE_TAG::TITLE_TAG)
	{
		// @@@
	}
	else if (sceneTag == SCENE_TAG::PLAY_TAG)
	{
		// @@@
	}
	else if (sceneTag == SCENE_TAG::RESULT_TAG)
	{
		// @@@
	}
}

/// <summary>
/// シーンの削除.
/// </summary>
void SceneManager::ClearScene()
{
	// 現在のシーンにnullptrが入っていた時.
	if (mNowScene == nullptr)
	{
		// 何もしない.
	}
	// もしnullptr以外の物が入っていた時.
	// 何かしらシーンのポインターが入っていた時.
	else
	{
		// 現在のシーンを削除する.
		delete mNowScene;

		// 変数にnullptrを代入.
		mNowScene = nullptr;
	}
}
