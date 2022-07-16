#pragma once
#include "Math.h"
#include "Background.h"

/// <summary>
/// それぞれシーンのタグ.
/// </summary>
enum class SCENE_TAG : short
{
	NONE_TAG = 0,         // シーンが無しの時.
	TITLE_TAG,            // シーンがタイトルの時.
	PLAY_TAG,             // シーンがプレイの時.
	RESULT_TAG,           // シーンがリザルトの時.
};

/// <summary>
/// シーンの基底クラス.
/// </summary>
class SceneBase
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	SceneBase();

	/// <summary>
	/// デストラクタ.
	/// </summary>
	virtual ~SceneBase();

	/// <summary>
	/// 更新関数、仮想関数.
	/// </summary>
	/// <returns>enumのSCENE_TAGを返す.</returns>
	virtual SCENE_TAG Update() = 0;

	/// <summary>
	/// 描画関数、仮想関数.
	/// </summary>
	virtual void Draw() = 0;

protected:
	Background* mBg;      // 背景クラスを保存する変数.
};