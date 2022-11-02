#pragma once
#include "SceneBase.h"
#include "Button.h"

/// <summary>
/// シーンのチュートリアルクラス.
/// SceneBaseを継承している.
/// </summary>
class Tutorial : public SceneBase
{
public :
    /// <summary>
    /// コンストラクタ.
    /// </summary>
    Tutorial();

    /// <summary>
    /// デストラクタ.
    /// </summary>
    ~Tutorial();
     
    /// <summary>
    /// 更新関数、オーバーライド関数.
    /// </summary>
    /// <param name="deltaTime">float型のデルタタイム.</param>
    /// <returns>SceneTag型のenumクラスを返す.</returns>
    SceneTag Updata(float deltaTime) override;

    /// <summary>
    /// 描画処理.
    /// </summary>
    void Draw() override;

    /// <summary>
    /// 入力処理関数、オーバーライド関数.
    /// </summary>
    void Input() override;

    const double MCOUNT_MAX;                   // 長押ししたときに増加し続ける値の最大値.

private:
    Button* mTutorialSkipBtn;                  // チュートリアルをスキップするButtonクラスの変数.
    BtnState mNowOnBtn;                        // このシーン中にオンマウス状態にあるボタンのステータス.

    double mCount;                             // 長押しした時のみ増加するカウンター.
};