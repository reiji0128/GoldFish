#include "Result.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ.
/// </summary>
Result::Result()
	// SceneBaseクラスの初期化、シーンタグはResultTagを指定する.
	:SceneBase(SceneBase::SceneTag::ResultTag)
	// タイトルに移行するButtonクラスの変数の初期化.
	,mTitleBtn(nullptr)
	// ゲームを閉じるButtonクラスの変数の初期化.
	,mExitBtn(nullptr)
	// 現在オンマウス状態にあるボタンのステータスの初期化.
	,mNowOnBtn(BtnState::None)
{
	// Backgroundクラスのコンストラクタ、Resultの背景を指定する.
	mBg = new Background(BgImgName[BgImgFileNum::ResultBg]);

	// Buttonクラスのコンストラクタ.
	mTitleBtn = new Button(ButtonImgName[ButtonImgFileNum::TitleBtn], BtnState::Title);
	mExitBtn = new Button(ButtonImgName[ButtonImgFileNum::ExitBtn], BtnState::Exit);

	// Buttonクラスの座標設定.@@@(仮)
	mTitleBtn->SetPosition(Vector2(100, 100));
	mExitBtn->SetPosition(Vector2(200, 200));

	// 現在オンマウス状態にあるボタンのステータスを代入.
	mNowOnBtn = mTitleBtn->GetBtnState();
}

/// <summary>
/// デストラクタ.
/// </summary>
Result::~Result()
{
	// メモリの削除.
	delete mBg;
	delete mTitleBtn;
	delete mExitBtn;
}

/// <summary>
/// 更新関数.
/// </summary>
/// <returns>SceneTag型のenumクラスを返す.</returns>
SceneBase::SceneTag Result::Updata()
{
	// mChangeSceneFlagがtrueの時.
	if (mChangeSceneFlag)
	{
		// リザルトしーんのタグを返す.
		return SceneTag::TitleTag;
	}
	// ゲームを終わらせるフラグがtrueの時.
	else if (mGameExitFlag)
	{
		// ゲームループが終了させるタグを返す.
		return SceneTag::ExitTag;
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
	mBg->Draw(ViewState::Normal);

	// Buttonクラスの描画関数.
	mTitleBtn->Draw(ViewState::Normal);
	mExitBtn->Draw(ViewState::Normal);
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

	// オンマウスした画像のステータスを取得する処理.
	{
		// １つ目のJoyPadが左キーボタンを押していた時.
		// かつ今のオンマウスした画像が別のステータスを持っていた時.
		if (pad1Input & PAD_INPUT_LEFT
			&& this->mNowOnBtn != this->mTitleBtn->GetBtnState())
		{
			// ボタンのステータスをStartに変更する.
			this->mNowOnBtn = this->mTitleBtn->GetBtnState();
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
		// デバック用としてキーボードで0ボタンを押した時.
		if (pad1Input & PAD_INPUT_1
			|| CheckHitKey(KEY_INPUT_0))
		{
			// もしボタンのステータスがTitleだった時.
			if (mNowOnBtn == this->mTitleBtn->GetBtnState())
			{
				// シーンを変えるフラグをtrueにする.
				mChangeSceneFlag = true;
			}
			// もしボタンのステータスがExitだった時.
			else if (mNowOnBtn == this->mExitBtn->GetBtnState())
			{
				// ゲームを閉じるシーンフラグをtrueにする.
				mGameExitFlag = true;
			}
		}
	}

}