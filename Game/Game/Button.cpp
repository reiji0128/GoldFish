#include "Button.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="fileName">const char*型の画像ファイルパス.</param>
Button::Button(const char* fileName, BtnState state)
	// 画像クラスの初期化をする.
	:Image(fileName)
	// 押したかどうかのフラグの初期化.
	//,mPushedBtnFlag(false)
	// そのボタンの持っているステータスの初期化.
	,mState(BtnState::None)
{
	// ステータスの代入.
	mState = state;
}

/// <summary>
/// デストラクタ.
/// </summary>
Button::~Button()
{
	// すでに画像ハンドルが-1の時はreturnを返す
	if (mImgHandle == -1)
	{
		return;
	}

	// 画像をメモリ上から削除する.
	DeleteGraph(mImgHandle);

	// 削除した後に-1を代入する.
	mImgHandle = -1;
}

/// <summary>
/// 更新関数、オーバーライド関数.
/// </summary>
/// <param name="deltaTime"></param>
void Button::Updata(float deltaTime)
{
}