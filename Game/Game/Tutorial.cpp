#include "Tutorial.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ.
/// </summary>
Tutorial::Tutorial()
     // SceneBaseクラスのコンストラクタ、SceneTagはTutorialTagにする.
    :SceneBase(SceneBase::SceneTag::TutorialTag)
{
    // Backgroundクラスのコンストラクタ、引数にタイトルのBackgroundを指定する.
    mBg = new Background(BgImgName[BgImgFileNum::TutorialBg]);
}

/// <summary>
/// デストラクタ.
/// </summary>
Tutorial::~Tutorial()
{
}

/// <summary>
/// 更新関数.
/// </summary>
/// <returns>SceneTag型のenumクラスを返す.</returns>
SceneBase::SceneTag Tutorial::Update()
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

    // 一つ目のJoyPadがAボタンを押していた時
    // またはデバッグ用としてキーボードで８ボタンを押したとき.
    if (pad1Input & PAD_INPUT_1
        || CheckHitKey(KEY_INPUT_8))
    {
        // シーンを変えるフラグをtrueにする.
        mChangeSceneFlag = true;
    }
}
