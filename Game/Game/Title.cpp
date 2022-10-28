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
	// 現在オンマウス状態にあるボタンのステータスの初期化.
	,mNowOnBtn(BtnState::None)
{
	// Backgroundクラスのコンストラクタ、引数にタイトルのBackgroundを指定する.
	mBg = new Background(BgImgName[BgImgFileNum::TitleBg]);

	// Buttonクラスのコンストラクタ.
	mStartBtn = new Button(ButtonImgName[ButtonImgFileNum::StartBtn],BtnState::Start);
	mExitBtn = new Button(ButtonImgName[ButtonImgFileNum::ExitBtn],BtnState::Exit);

	// Buttonクラスの座標設定.@@@(仮)
	mStartBtn->SetPosition(Vector2(100, 100));
	mExitBtn->SetPosition(Vector2(200, 200));

	// 現在オンマウス状態にあるボタンのステータスを代入.
	mNowOnBtn = mStartBtn->GetBtnState();
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
		return SceneTag::TutorialTag;
	}
	// ゲームを終わらせるフラグがtrueの時.
	else if (mGameExitFlag)
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
	mBg->Draw(ViewState::Normal);

	// Buttonクラスの描画処理.
	mStartBtn->Draw(ViewState::Normal);
	mExitBtn->Draw(ViewState::Normal);
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

	// オンマウスした画像のステータスを取得する処理.
	{
		// １つ目のJoyPadが左キーボタンを押していた時.
		// かつ今のオンマウスした画像が別のステータスを持っていた時.
		if (pad1Input & PAD_INPUT_LEFT
			&& this->mNowOnBtn != this->mStartBtn->GetBtnState())
		{
			// ボタンのステータスをStartに変更する.
			this->mNowOnBtn = this->mStartBtn->GetBtnState();
		}
		// １つ目のJoyPadが右キーボタンを押していた時.
		// かつ今のオンマウスした画像が別のステータスを持っていた時.
		else if (pad1Input & PAD_INPUT_RIGHT
			&& this->mNowOnBtn != this->mExitBtn->GetBtnState())
		{
			// ボタンのステータスをExitに変更する.
			this->mNowOnBtn = this->mExitBtn->GetBtnState();
		}
	}

	// 現在オンマウスしているボタン画像のステータスによって変わる処理.
	{
		// １つ目のJoyPadがAボタンを押していた時.
		// デバッグ用としてキーボードで7ボタンを押した時.
		if (pad1Input & PAD_INPUT_1
			|| CheckHitKey(KEY_INPUT_7))
		{
			// もしボタンのステータスがStartだった時.
			if (mNowOnBtn == mStartBtn->GetBtnState())
			{
				// チュートリアルシーンをtrueにする.
				mChangeSceneFlag = true;
			}
			// もしボタンのステータスがExitだった時.
			else if (mNowOnBtn == mExitBtn->GetBtnState())
			{
				// ゲームを閉じるシーンフラグをtrueにする.
				mGameExitFlag = true;
			}
		}
	}
}