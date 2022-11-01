#pragma once
#include "SceneBase.h"
#include "FPS.h"
#include "PoiRed.h"
#include "PoiBlue.h"

//------------------------------
// ここにゲームプレイ中に必要なヘッダーをインクルードしてください.


// コンスタント変数(static).
static const int MWidth = 1920;
static const int MHeight = 1080;

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

	// コンスタント変数.
	const int MColorBitNum;

	// ループを抜けるかどうかのbool型変数、trueの場合はループを続ける、falseの場合はループを抜ける.
	bool mRunningFlag;

	// 現在のシーンクラスを持つ変数.
	SceneBase* mNowSceneClass;

	// １ループ前のシーンタグを保存する変数.
	SceneBase::SceneTag mReturnTag;

	// FPSクラスを持つ変数.
	FPS* mFps;

public:// ------------------セッター・ゲッター関数-------------------------

	/// <summary>
	/// 最初のシーンの代入.
	/// </summary>
	/// <param name="firstScene">SceneBase型の一番最初に表示するシーンクラス.</param>
	void SetFirstScene(SceneBase* firstScene)
	{
		// 現在のシーンクラスへと代入する.
		mNowSceneClass = firstScene;
	};
};

