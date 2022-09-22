#include "Result.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ.
/// </summary>
Result::Result()
	:SceneBase(SceneBase::SceneTag::RESULT_TAG)
{
	mBg = new Background(BgImgName[BgImgFileNum::RESULT_IMG]);
}

/// <summary>
/// デストラクタ.
/// </summary>
Result::~Result()
{
}

/// <summary>
/// 更新関数.
/// </summary>
/// <param name="deltaTime">float型のデルタタイムの引数.</param>
/// <returns>SceneTag型のenumクラスを返す.</returns>
SceneBase::SceneTag Result::Update()
{
	// タイトルシーンへの移行処理.
	if (mChangeSceneFlag)
	{
		return SceneTag::TITLE_TAG;
	}

	// それ以外はこのシーンを返す.
	return mNowSceneTag;
}

/// <summary>
/// 描画関数.
/// </summary>
void Result::Draw()
{
	mBg->Draw();
}

void Result::Input()
{
	int pad1Input;
	pad1Input = GetJoypadInputState(DX_INPUT_PAD1);

	if (pad1Input & PAD_INPUT_1)
	{
		// シーンを変えるフラグをtrueにする.
		mChangeSceneFlag = true;
	}
}