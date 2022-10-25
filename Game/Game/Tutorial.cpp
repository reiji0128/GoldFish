#include "Tutorial.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ.
/// </summary>
Tutorial::Tutorial()
     // SceneBaseクラスのコンストラクタ、SceneTagはTutorialTagにする.
    :SceneBase(SceneBase::SceneTag::TutorialTag)
    // 長押ししたときの値の最大値の初期化.
    ,MCOUNT(100)
    // チュートリアルスキップボタンの初期化.
    ,mTutorialSkipBtn(nullptr)
{
    // Backgroundクラスのコンストラクタ、引数にタイトル画像を指定する.
    mBg = new Background(BgImgName[BgImgFileNum::TutorialBg]);

    // Buttonクラスのコンストラクタ、引数にボタン画像とステータスを指定する.
    mTutorialSkipBtn = new Button(ButtonImgName[ButtonImgFileNum::TutorialSkip],BtnState::TutoSkip);
}

/// <summary>
/// デストラクタ.
/// </summary>
Tutorial::~Tutorial()
{
    // メモリ削除.
    delete mBg;
    delete mTutorialSkipBtn;
}

/// <summary>
/// 更新関数.
/// </summary>
/// <returns>SceneTag型のenumクラスを返す.</returns>
SceneBase::SceneTag Tutorial::Updata()
{
    // mChangeSceneFlagがtrueだった時.
    if (mChangeSceneFlag)
    {
        // PlayTagを返す(プレイシーンへ移行).
        return SceneTag::PlayTag;
    }

    // 現在のシーンを返す.
    return mNowSceneTag;
}

/// <summary>
/// 描画関数.
/// </summary>
void Tutorial::Draw()
{
    // Backgroundクラスの描画処理.
    mBg->Draw();

    // Buttonクラスの描画処理.
    mTutorialSkipBtn->Draw();
}

/// <summary>
/// シーンを変える際の入力処理関数.
/// </summary>
void Tutorial::Input()
{
    // 現在のパッドの押したボタンの入力状態を保存する関数.
    int pad1Input;

    // 一つ目のJoyPadの押したボタンの入力情報を取得.
    pad1Input = GetJoypadInputState(DX_INPUT_PAD1);

    {
        if(pad1Input & PAD_INPUT_1
            && this->mNowBtnState)
    }

    // 一つ目のJoyPadがAボタンを押していた時
    // またはデバッグ用としてキーボードで８ボタンを押したとき.
    if (pad1Input & PAD_INPUT_1
        || CheckHitKey(KEY_INPUT_8))
    {
        // シーンを変えるフラグをtrueにする.
        mChangeSceneFlag = true;
    }
}
