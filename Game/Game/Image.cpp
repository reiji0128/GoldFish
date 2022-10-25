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
{
    // 画像ハンドルを読み込む.
    mImgHandle = LoadGraph(fileName);

    // 画像ハンドルのサイズの取得.
    GetGraphSizeF(mImgHandle, &mScale.x, &mScale.y);
}
