#include "Image.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="fileName">const char*型の画像のファイルパス.</param>
Image::Image(const char* fileName)
// 座標保存変数の初期化.
    :mPos(Vector2::Zero)
    // 画像サイズを保存する変数の初期化.
    , mScale(Vector2::Zero)
    // 画像ハンドル保存変数の初期化.
    , mImgHandle(-1)
    // 描画の際に使用するステータスを保存する変数.
    , mState(ViewState::None)
    // 円形のゲージを表示する変数の初期化.
    , mCirclePercent(0.0f)
    // 円形のゲージを動かす為の変数の初期化.
    , mCirclePercentAdd(0.0f)
    // 円形のゲージを動かすかどうかの変数の初期化.
    , mCircleMoveFlag(false)
{
    // 画像ハンドルを読み込む.
    mImgHandle = LoadGraph(fileName);

    // 画像ハンドルのサイズの取得.
    GetGraphSizeF(mImgHandle, &mScale.x, &mScale.y);
}

/// <summary>
/// ステータス別の描画関数.
/// </summary>
void Image::Draw()
{
    // ステータスが円形のゲージ状の時.
    if (mState == ViewState::CircleGauge
        && mCircleMoveFlag)
    {
        // 描画処理.
        DrawCircleGaugeF(mPos.x, mPos.y, mCirclePercent, mImgHandle, true);
    }
    // それ以外の時.
    else
    {
        DrawGraph(mPos.x, mPos.y, mImgHandle, true);
    }
}