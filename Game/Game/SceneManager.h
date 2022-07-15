#pragma once
#include "SceneBase.h"
#include <DxLib.h>

/// <summary>
/// シーンのマネージャークラス.
/// </summary>
class SceneManager
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	SceneManager();

	/// <summary>
	/// デストラクタ.
	/// </summary>
	~SceneManager();

	/// <summary>
	/// ゲームループ関数.
	/// </summary>
	void GameRoop();

	/// <summary>
	/// シーン生成.
	/// </summary>
	/// <param name="sceneTag">次のシーンを判定するときのenum class型のタグ.</param>
	void CreatsScene(SCENE_TAG sceneTag);

	/// <summary>
	/// シーンの削除.
	/// </summary>
	void ClearScene();

private:
	SceneBase* mNowScene;        // 現在のシーンを保存する変数.
};

