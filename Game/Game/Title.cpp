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
	// 現在Joypadがオンマウス状態にある変数の初期化.
	,mNowBtnState(btnState::Start)
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
	Input();

	// シーンを変えるフラグがtrueの時.
	if (mChangeSceneFlag)
	{
		// タイトルシーンのタグを返す.
		return SceneTag::TitleTag;
	}
	// ゲームを終わらせるフラグがtrueの時.
	else if (mExitGameFlag)
	{
		// ゲームループを終了させるタグを返す.
		return SceneTag::ExitTag;
	}

	// それ以外の時は現在のシーンタグを返す.
	return mNowSceneTag;
}

/// <summary>
/// 描画処理.
/// </summary>
void Title::Draw()
{
	// Backgroundクラスの描画処理.
	mBg->Draw();

	// buttonクラスの描画処理.
	mStartBtn->Draw();
	mExitBtn->Draw();
}

/// <summary>
/// シーンを変える際の入力処理関数.
/// </summary>
void Title::Input()
{
	// 現在のパッドの押したボタンの入力状態を保存する変数.
	int pad1Input;

	// １つ目のJoyPadの押したボタンの入力状態を取得.
	pad1Input = GetJoypadInputState(DX_INPUT_PAD1);

	// １つ目のJoyPadが左キーボタンを押していた時.
	if (pad1Input & PAD_INPUT_LEFT)
	{
		// ボタンのステータスをStartに変更する.
		mNowBtnState = btnState::Start;
	}
	// １つ目のJoyPadが右キーボタンを押していた時.
	else if (pad1Input & PAD_INPUT_RIGHT)
	{
		// ボタンのステータスをExitに変更する.
		mNowBtnState = btnState::Exit;
	}

	// １つ目のJoyPadがAボタンを押していた時.
	// デバッグ用としてキーボードで7ボタンを押した時.
	if (pad1Input & PAD_INPUT_1
		|| CheckHitKey(KEY_INPUT_7))
	{
		// もしボタンのステータスがStartだった時.
		if (mNowBtnState == btnState::Start)
		{
			// チュートリアルシーンを返す.
			mChangeSceneFlag = true;
		}
		// もしボタンのステータスがExitだった時.
		else if(mNowBtnState == btnState::Exit)
		{
			// ゲームを閉じるシーンタグを返す.
			mExitGameFlag = true;
		}
	}
}