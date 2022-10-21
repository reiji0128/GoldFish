#pragma once
#include "Math.h"

/// <summary>
/// 画像関連クラス.
/// </summary>
class Image
{
public :
    /// <summary>
    /// コンストラクタ.
    /// </summary>
    /// <param name="fileName">const char*型の画像ファイルパス.</param>
    Image(const char* fileName);

    /// <summary>
    /// デストラクタ.
    /// </summary>
    virtual ~Image() {};

    /// <summary>
    /// 更新関数、仮想関数.
    /// </summary>
    /// <param name="deltaTime">float型のデルタタイムの引数.</param>
    virtual void Updata(float deltaTime) = 0;

    /// <summary>
    /// 描画関数、仮想関数.
    /// </summary>
    virtual void Draw() = 0;

protected:
    Vector2 mPos;        // 座標保存変数.
    Vector2 mScale;      // 画像の大きさを保存する変数.
    int mImgHandle;      // 画像ハンドル保存変数.

public :// -------------------セッター・ゲッター関数--------------------

    /// <summary>
    /// 画像の座標を設定する関数.
    /// </summary>
    /// <param name="pos">Vector2型の変数.</param>
    void SetPosition(Vector2 pos)
    {
        this->mPos = pos;
    }

    /// <summary>
    /// 現在の座標を返す.
    /// </summary>
    /// <returns>Vector2型の座標変数を返す.</returns>
    Vector2 GetPosition()
    {
        return this->mPos;
    }

    /// <summary>
    /// 現在の画像サイズを返す.
    /// </summary>
    /// <returns>Vector2型の画像の大きさを保存している変数を返す.</returns>
    Vector2 GetScale()
    {
        return this->mScale;
    }
};