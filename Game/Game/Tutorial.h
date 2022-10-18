#pragma once
#include "SceneBase.h"

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
    /// <returns>SceneTag型のenumクラスを返す.</returns>
    SceneTag Update() override;

    /// <summary>
    /// 描画処理.
    /// </summary>
    void Draw() override;

    /// <summary>
    /// 入力処理関数、オーバーライド関数.
    /// </summary>
    void Input() override;

private:

};

