#include "Play.h"
#include "DxLib.h"
#include "FishManager.h"
#include "PoiManager.h"

/// <summary>
/// コンストラクタ.
/// </summary>
Play::Play()
	// SceneBaseクラスの初期化、タグはPlayに指定する.
	:SceneBase(SceneBase::SceneTag::PlayTag)
{
	// Backgroundクラスのコンストラクタ、Playの背景を指定する.
	mBg = new Background(BgImgName[BgImgFileNum::PlayBg]);
	FishManager::CreatePool(1, 1, 1, 1);
}

/// <summary>
/// デストラクタ.
/// </summary>
Play::~Play()
{
}

/// <summary>
/// 更新処理.
/// </summary>
/// <returns>SceneBaseのenumClassであるSceneTag型を返す.</returns>
SceneBase::SceneTag Play::Update()
{
	// mChangeSceneFlagがtrueだった時
	if (mChangeSceneFlag)
	{
		// SceneTagをResultTagにする.
		return SceneTag::ResultTag;
	}

	// それ以外の場合は現在のシーンを返す.
	return mNowSceneTag;
}

/// <summary>
/// 描画関数.
/// </summary>
void Play::Draw()
{
	// Backgroundクラスの描画処理.
	mBg->Draw();
	// FishManagerの描画処理
	FishManager::Draw();

	PoiManager::Draw();
	
}

/// <summary>
/// シーンを変える際の入力処理関数.
/// </summary>
void Play::Input()
{
	// ここでPlayを終了した際のFlagやState等を記入する.@@@
	// またはデバッグ用としてキーボードの9ボタンを押した時.
	if (CheckHitKey(KEY_INPUT_9))
	{
		// mChangeSceneFlagをtrueにする
		mChangeSceneFlag = true;
	}
}