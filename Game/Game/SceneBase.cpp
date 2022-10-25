#include "SceneBase.h"

// 現在のシーンの初期化.
SceneBase::SceneTag SceneBase::mNowSceneTag =
SceneTag::InitTag;

/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="nowTag">現在のシーンタグ、enumClass型変数.</param>
SceneBase::SceneBase(SceneTag nowTag)
	:mChangeSceneFlag(false)         // シーンを変えるかどうかのフラグの初期化.
	,mGameExitFlag(false)            // ゲームを終了させるかどうかのフラグの初期化.
	,mBg(nullptr)                    // Backgroundクラスの初期化.
{
	// シーンタグの更新.
	mNowSceneTag = nowTag;
}