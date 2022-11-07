#include "Tutorial.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ.
/// </summary>
Tutorial::Tutorial()
     // SceneBaseクラスのコンストラクタ、SceneTagはTutorialTagにする.
    :SceneBase(SceneBase::SceneTag::TutorialTag)
    // 長押ししたときの値の最大値の初期化.
    ,MCOUNT_MAX(200.0f)
    // チュートリアルスキップボタンの初期化.
    ,mTutorialSkipBtn(nullptr)
    // 長押しした時のみ増加する変数の初期化.
    ,mCount(0.0f)
    // シーン中にオンマウスしているボタンのステータスを保存する変数の初期化.
    ,mNowOnBtn(BtnState::None)
{
    // Backgroundクラスのコンストラクタ、引数にタイトル画像を指定する.
    mBg = new Background(BgImgName[BgImgFileNum::PlayBg]);

    // Buttonクラスのコンストラクタ、引数にボタン画像とステータスを指定する.
    mTutorialSkipBtn = new Button(ButtonImgName[ButtonImgFileNum::TutorialSkip],BtnState::TutoSkip);

    // Buttonクラスの座標設定.
    mTutorialSkipBtn->SetPosition(Vector2((mTutorialSkipBtn->GetScale().x / 2) + 50, (mTutorialSkipBtn->GetScale().y / 2) + 50));
}

/// <summary>
/// デストラクタ.
/// </summary>
Tutorial::~Tutorial()
{
    // メモリ削除.
    delete mBg;
    delete mTutorialSkipBtn;

    // メモリの初期化.
    mBg = nullptr;
    mTutorialSkipBtn = nullptr;
}

/// <summary>
/// 更新関数、オーバーライド関数.
/// </summary>
/// <param name="deltaTime">float型のデルタタイム.</param>
/// <returns>SceneTag型のenumクラスを返す.</returns>
SceneBase::SceneTag Tutorial::Updata(float deltaTime)
{
    // 入力処理.
    Input();

    // Buttonクラスの更新関数.
    mTutorialSkipBtn->Updata(deltaTime, ViewState::CircleGauge);

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

    // 一つ目のJoyPadがAボタンを押していた時.
    if (pad1Input & PAD_INPUT_1)
    {
        // 長押し変数を増加する
        mCount += mTutorialSkipBtn->GetCirclePercentAdd();

        // ゲージを表示するためにフラグをtrueにする.
        mTutorialSkipBtn->SetCircleFlag(true);

        // 長押しカウントが既定値を超えた時.
        if (mCount > MCOUNT_MAX)
        {
            // ゲージを増やすフラグをfalseにする.
            mTutorialSkipBtn->SetCircleFlag(false);

            // プレイシーンを返す.
            mChangeSceneFlag = true;
        }
    }
    // それ以外の時.
    else
    {
        // カウントを０に戻す.
        mCount = 0;

        // ゲージを最初からにする.
        mTutorialSkipBtn->SetCirclePercent(0.0f);

        // ゲージを増やすフラグをfalseにする.
        mTutorialSkipBtn->SetCircleFlag(false);
    }

    // またはデバッグ用としてキーボードで８ボタンを押したとき.
    if (CheckHitKey(KEY_INPUT_8))
    {
        // シーンを変えるフラグをtrueにする.
        mChangeSceneFlag = true;
    }
}
