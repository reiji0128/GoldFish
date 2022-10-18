#pragma once
#include "Math.h"
#include "Background.h"

/// <summary>
/// シーンの基底クラス.
/// </summary>
class SceneBase
{
public:
	/// <summary>
	/// それぞれシーンのタグ.
	/// </summary>
	enum class SceneTag
	{
		NoneTag = 0,         // シーンが無しの時.
		InitTag,             // シーンが初期状態の時.
		TitleTag,            // シーンがタイトルの時.
		TutorialTag,         // シーンがチュートリアルの時.
		PlayTag,             // シーンがプレイの時.
		ResultTag,           // シーンがリザルトの時.
		ExitTag,             // シーンが閉じる時.
	};

	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="nowTag">SceneTag型の引数.</param>
	SceneBase(SceneTag nowTag);

	/// <summary>
	/// デストラクタ.
	/// </summary>
	~SceneBase() {};

	/// <summary>
	/// 更新関数、仮想関数.
	/// </summary>
	/// <param name="delteTime">float型のデルタタイムの引数.</param>
	/// <returns>SceneTag型のenumクラスを返す.</returns>
	virtual SceneBase::SceneTag Updata() = 0;

	/// <summary>
	/// 入力処理関数、仮想関数.
	/// </summary>
	virtual SceneTag Input() = 0;

	/// <summary>
	/// 描画関数、仮想関数.
	/// </summary>
	virtual void Draw() = 0;

	static SceneTag mNowSceneTag;        // 現在のシーンタグ.

protected:
	Background* mBg;                     // 背景の生成.
	bool mChangeSceneFlag;               // シーン移動フラグ.
};