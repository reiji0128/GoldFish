#include "Title.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ.
/// </summary>
Title::Title()
	// SceneBaseクラスのコンストラクタ、SceneTagはTitleTagにする.
	:SceneBase(SceneBase::SceneTag::TitleTag)
	//,mStartButton(nullptr)
	//,mExitButton(nullptr)
	//,mStartFlag(false)
{
	// Backgroundクラスのコンストラクタ、引数にタイトルのBackgroundを指定する.
	mBg = new Background(BgImgName[BgImgFileNum::TitleBg]);

	//mStartButton = new Button(ButtonImgName[ButtonImgFileNum::START_BUTTON_IMG]);
	//mExitButton = new Button(ButtonImgName[ButtonImgFileNum::EXIT_BUTTON_IMG]);
}

/// <summary>
/// デストラクタ.
/// </summary>
Title::~Title()
{
}

/// <summary>
/// 更新関数.
/// </summary>
/// <returns>SceneTag型のenumクラスを返す.</returns>
SceneBase::SceneTag Title::Update()
{
	// mChangeSceneFlagがtrueだった時.
	if (mChangeSceneFlag)
	{
		// PlayTagを返す.
		return SceneTag::PlayTag;
	}

	// 現在のシーンタグを返す.
	return mNowSceneTag;
}

/// <summary>
/// 描画処理.
/// </summary>
void Title::Draw()
{
	// Backgroundクラスの描画処理.
	mBg->Draw();
}

/// <summary>
/// 入力処理関数、オーバーライド関数.
/// </summary>
void Title::Input()
{
	// 現在のパッドの押したボタンの入力状態を保存する変数.
	int pad1Input;

	// １つ目のJoyPadの押したボタンの入力状態を取得.
	pad1Input = GetJoypadInputState(DX_INPUT_PAD1);

	// １つ目のJoyPadがAボタンを押していた時.
	// デバック用としてキーボードで8ボタンを押した時.
	if (pad1Input & PAD_INPUT_1
		|| CheckHitKey(KEY_INPUT_8))
	{
		// シーンを変えるフラグをtrueにする.
		mChangeSceneFlag = true;
	}
}