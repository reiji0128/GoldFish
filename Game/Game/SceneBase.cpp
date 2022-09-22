#include "SceneBase.h"

// 現在のシーンの初期化.
SceneBase::SceneTag SceneBase::mNowSceneTag =
SceneTag::INIT_TAG;

/// <summary>
/// コンストラクタ.
/// </summary>
SceneBase::SceneBase(SceneTag nowTag)
	:mChangeSceneFlag(false)
	,mBg(nullptr)
{
	// シーンタグの更新.
	mNowSceneTag = nowTag;
}