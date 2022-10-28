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
    ,mScale(Vector2::Zero)
    // 画像ハンドル保存変数の初期化.
    ,mImgHandle(-1)
    // 円形のゲージを表示する変数の初期化.
    ,mCircePercent(0.0f)
{
    // 画像ハンドルを読み込む.
    mImgHandle = LoadGraph(fileName);

    // 画像ハンドルのサイズの取得.
    GetGraphSizeF(mImgHandle, &mScale.x, &mScale.y);
}

/// <summary>
/// ステータス別の描画関数.
/// </summary>
/// <param name="state">ViewState型のenum classの変数.</param>
void Image::Draw(ViewState state)
{
    // ステータスが通常の時.
    if (state == ViewState::Normal)
    {
        // 描画処理.
        DrawGraph((int)mPos.x, (int)mPos.y, mImgHandle, true);
    }
    // ステータスが円形のゲージ状の時.
    else if (state == ViewState::CircleGauge)
    {
        // 円形のゲージを保存する変数の代入.
        mCircePercent += 0.3f;
        // 描画処理.
        DrawCircleGaugeF(mPos.x, mPos.y, mCircePercent, mImgHandle, true);
    }
}