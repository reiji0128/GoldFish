#include "SceneBase.h"
#include "Background.h"

/// <summary>
/// コンストラクタ.
/// </summary>
SceneBase::SceneBase()
{
	this->mBg = new Background();
}

/// <summary>
/// デストラクタ.
/// </summary>
SceneBase::~SceneBase()
{
}
