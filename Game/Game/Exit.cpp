#include "Exit.h"

/// <summary>
/// コンストラクタ.
/// </summary>
Exit::Exit()
    :SceneBase(SceneBase::SceneTag::ExitTag)
{
}

/// <summary>
/// デストラクタ.
/// </summary>
Exit::~Exit()
{
}

/// <summary>
/// 更新関数.
/// </summary>
/// <returns>SceneTag型のenumクラスの変数を返す</returns>
SceneBase::SceneTag Exit::Updata()
{
    // 入力処理.
    Input();

    // 終了シーンタグを返す.
    return SceneTag::ExitTag;
}

/// <summary>
/// シーンを変える際の入力処理関数.
/// </summary>
void Exit::Input()
{
}

/// <summary>
/// 描画処理.
/// </summary>
void Exit::Draw()
{
}
