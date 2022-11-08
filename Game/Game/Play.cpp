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
	FishManager::InitPool();
}

/// <summary>
/// デストラクタ.
/// </summary>
Play::~Play()
{
	// メモリの削除.
	delete mBg;

	// メモリの初期化.
	mBg = nullptr;
}

/// <summary>
/// 更新関数、オーバーライド関数.
/// </summary>
/// <param name="deltaTime">float型のデルタタイム.</param>
/// <returns>SceneTag型のenumクラスを返す.</returns>
SceneBase::SceneTag Play::Updata(float deltaTime)
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
	
	//UIクラスの描画
	ui->Draw();
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