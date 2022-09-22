#include "Title.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ.
/// </summary>
Title::Title()
	:SceneBase(SceneBase::SceneTag::TITLE_TAG)
	,mStartButton(nullptr)
	,mExitButton(nullptr)
	,mStartFlag(false)
{
	mBg = new Background(BgImgName[BgImgFileNum::TITLE_IMG]);

	mStartButton = new Button(ButtonImgName[ButtonImgFileNum::START_BUTTON_IMG]);
	mExitButton = new Button(ButtonImgName[ButtonImgFileNum::EXIT_BUTTON_IMG]);
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
/// <param name="deltaTime">float型のデルタタイムの引数.</param>
/// <returns>SceneTag型のenumクラスを返す.</returns>
SceneBase::SceneTag Title::Update()
{
	if (mChangeSceneFlag)
	{
		return SceneTag::PLAY_TAG;
	}

	return mNowSceneTag;
}

void Title::Draw()
{
	mBg->Draw();
}

/// <summary>
/// 入力処理関数、オーバーライド関数.
/// </summary>
void Title::Input()
{
	int pad1Input;
	pad1Input = GetJoypadInputState(DX_INPUT_PAD1);

	if (pad1Input & PAD_INPUT_1)
	{
		// シーンを変えるフラグをtrueにする.
		mChangeSceneFlag = true;
	}
	else
	{
		mChangeSceneFlag = false;
	}
}