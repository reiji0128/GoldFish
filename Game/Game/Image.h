#pragma once
#include "Math.h"

/// <summary>
/// 画像の描画処理別のステータス.
/// </summary>
enum class ViewState : unsigned short
{
    None = 0,                 // 画像の描画処理がない時.
    Normal,                   // 画像の描画処理が普通に表示される時.
    CircleGauge,              // 画像の描画処理が円形に表示される時.
    Button,                   // 画像の描画処理がボタンとして表示される時.

    MaxDrawState,             // 画像の描画処理のパターン数.
};

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
    virtual void Updata(float deltaTime, ViewState state) {};

    /// <summary>
    /// ステータス別の描画関数、仮想関数.
    /// </summary>
    void Draw();

protected:
    Vector2 mPos;             // 座標保存変数.
    Vector2 mScale;           // 画像の大きさを保存する変数.
    int mImgHandle;           // 画像ハンドル保存変数.

    ViewState mState;         // 描画の際に使用するステータスを保存する変数.

    double mCirclePercent;    // 円形のゲージをどの程度まで表示するのかを代入する変数(double型).
    double mCirclePercentAdd; // 円形のゲージが増えていく値を保存する変数(double型).
    bool mCircleMoveFlag;     // 円形のゲージが増えていくかどうかのフラグ、trueなら動きfalseなら動かない.
    bool mCircleMaxFlag;      // 円形のゲージが最大になったかどうかのフラグ、trueなら360度描画されておりfalseなら360度の描画はされていない.
    const double MPercentAdd; // ゲージを増やす定数量(double型).

public :// -------------------セッター・ゲッター関数--------------------

    /// <summary>
    /// 画像の座標を設定する関数.
    /// </summary>
    /// <param name="pos">Vector2型の変数.</param>
    void SetPosition(Vector2 pos) { this->mPos = pos; }

    /// <summary>
    /// 現在の座標を返す.
    /// </summary>
    /// <returns>Vector2型の座標変数を返す.</returns>
    Vector2 GetPosition() { return this->mPos; }

    /// <summary>
    /// 現在の画像サイズを返す.
    /// </summary>
    /// <returns>Vector2型の画像の大きさを保存している変数を返す.</returns>
    Vector2 GetScale() { return this->mScale; }

    /// <summary>
    /// ゲージが増える量の指定数の設定
    /// </summary>
    /// <param name="setNum">ゲージが増える量(double型)、最大100.</param>
    void SetCirclePercent(double setNum) { this->mCirclePercent = setNum; }

    ///// <summary>
    ///// ゲージが増える量の設定.
    ///// </summary>
    ///// <param name="add">double型のゲージ増加変数.</param>
    //void SetCirclePercentAdd(double add) { this->mCirclePercentAdd = add; }

    /// <summary>
    /// ゲージが増える量の取得.
    /// </summary>
    /// <returns>double型のゲージ増加変数.</returns>
    double GetCirclePercentAdd() { return this->mCirclePercentAdd; }

    /// <summary>
    /// ゲージが増えるかどうかのフラグの設定.
    /// </summary>
    /// <param name="flag">bool型の変数.</param>
    void SetCircleFlag(bool flag) { this->mCircleMoveFlag = flag; }
};