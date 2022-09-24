#include "Result.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ.
/// </summary>
Result::Result()
	// SceneBaseクラスの初期化、シーンタグはResultTagを指定する.
	:SceneBase(SceneBase::SceneTag::ResultTag)
{
	// Backgroundクラスのコンストラクタ、Resultの背景を指定する.
	mBg = new Background(BgImgName[BgImgFileNum::ResultBg]);
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
/// <returns>SceneTag型のenumクラスを返す.</returns>
SceneBase::SceneTag Result::Update()
{
	// mChangeSceneFlagがtrueの時.
	if (mChangeSceneFlag)
	{
		// ResultTagを返す.
		return SceneTag::TitleTag;
	}

	// それ以外はこのシーンを返す.
	return mNowSceneTag;
}

/// <summary>
/// 描画関数.
/// </summary>
void Result::Draw()
{
	// Backgroundクラスの描画関数.
	mBg->Draw();
}

/// <summary>
/// シーンを変える際の入力処理関数.
/// </summary>
void Result::Input()
{
	// 現在のパッドの押したボタンの入力状態を保存する変数.
	int pad1Input;

	// １つ目のJoyPadの押したボタンの入力状態を取得.
	pad1Input = GetJoypadInputState(DX_INPUT_PAD1);

	// １つ目のJoyPadがAボタンを押していた時.
	// デバック用としてキーボードで0ボタンを押した時.
	if (pad1Input & PAD_INPUT_1
		|| CheckHitKey(KEY_INPUT_0))
	{
		// シーンを変えるフラグをtrueにする.
		mChangeSceneFlag = true;
	}
}