#pragma once
#include "Math.h"

/// <summary>
/// それぞれシーンのタグ.
/// </summary>
enum SCENE_TAG
{
	NONE_TAG = 0,
	TITLE_TAG,
	PLAY_TAG,
	RESULT_TAG,
};

/// <summary>
/// SceneBaseクラス.
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
};