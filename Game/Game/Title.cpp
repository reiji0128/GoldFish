#include "Title.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ.
/// </summary>
Title::Title()
	// SceneBaseクラスのコンストラクタ、SceneTagはTitleTagにする.
	:SceneBase(SceneBase::SceneTag::TitleTag)
	// スタートボタンの初期化.
	,mStartBtn(nullptr)
	// ゲームを閉じるボタンの初期化.
	,mExitBtn(nullptr)
{
	// Backgroundクラスのコンストラクタ、引数にタイトルのBackgroundを指定する.
	mBg = new Background(BgImgName[BgImgFileNum::TitleBg]);

	// Buttonクラスのコンストラクタ.
	mStartBtn = new Button(ButtonImgName[ButtonImgFileNum::StartBtn]);
	mExitBtn = new Button(ButtonImgName[ButtonImgFileNum::ExitBtn]);

}

/// <summary>
/// デストラクタ.
/// </summary>
Title::~Title()
{
	// メモリの削除.
	delete mBg;
	delete mStartBtn;
	delete mExitBtn;
}

/// <summary>
/// 更新関数.
/// </summary>
/// <returns>SceneTag型のenumクラスを返す.</returns>
SceneBase::SceneTag Title::Updata()
{
	// 入力処理.
	return Input();
}

/// <summary>
/// 描画処理.
/// </summary>
void Title::Draw()
{
	// Backgroundクラスの描画処理.
	mBg->Draw();

	mStartBtn->Draw();
	mExitBtn->Draw();
}

/// <summary>
/// シーンを変える際の入力処理関数.
/// </summary>
SceneBase::SceneTag Title::Input()
{
	// 現在のパッドの押したボタンの入力状態を保存する変数.
	int pad1Input;

	// １つ目のJoyPadの押したボタンの入力状態を取得.
	pad1Input = GetJoypadInputState(DX_INPUT_PAD1);

	// １つ目のJoyPadがAボタンを押していた時.
	// デバッグ用としてキーボードで7ボタンを押した時.
	if (pad1Input & PAD_INPUT_1
		|| CheckHitKey(KEY_INPUT_7))
	{
		// もしボタンのステータスがStartだった時.
		if (mNowBtnState == btnState::Start)
		{
			// チュートリアルシーンを返す.
			return SceneTag::TutorialTag;
		}
		// もしボタンのステータスがExitだった時.
		else if(mNowBtnState == btnState::Exit)
		{
			// ゲームを閉じるシーンタグを返す.
			return SceneTag::ExitTag;
		}
	}

	// それ以外は自分のシーンを返す.
	return mNowSceneTag;
}