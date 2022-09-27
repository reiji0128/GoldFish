#pragma once
#include "SceneBase.h"
#include "FPS.h"
#include "Poi.h"

//------------------------------
// ここにゲームプレイ中に必要なヘッダーをインクルードしてください.


/// <summary>
/// ゲームマネージャークラス.
/// </summary>
class GameManager
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	GameManager();

	/// <summary>
	/// デストラクタ.
	/// </summary>
	~GameManager() {};

	/// <summary>
	/// 初期化処理.
	/// </summary>
	/// <returns>返り値がtrueの時は成功、falseの時は失敗.</returns>
	bool Initialize();

	/// <summary>
	/// ゲームループ.
	/// </summary>
	void GameLoop();

	/// <summary>
	/// 終了処理.
	/// </summary>
	void terminate();

private:
	/// <summary>
	/// mReturnTagを使用した新しいシーンを生成する関数.
	/// </summary>
	void CreateScene();

	/// <summary>
	/// 入力処理関数.
	/// </summary>
	void ProcessInput();

	/// <summary>
	/// ゲームの更新処理.
	/// </summary>
	void UpdateGame();

	/// <summary>
	/// ゲームの描画処理.
	/// </summary>
	void DrawGame();

	const int MWidth;
	const int MHeight;
	const int MColorBitNum;

	bool mRunningFlag;

	SceneBase* mNowScene;
	SceneBase::SceneTag mReturnTag;

	FPS* mFps;

	Poi* mPoi1;
	Poi* mPoi2;

public:
	void SetFirstScene(SceneBase* firstScene)
	{
		mNowScene = firstScene;
	};
};

