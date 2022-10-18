#include "Button.h"
#include "DxLib.h"

/// <summary>
/// 
/// </summary>
/// <param name="fileName"></param>
Button::Button(const char* fileName)
	:ImageBase(fileName)
{
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
	// オンマウス？(ぶっちゃけパッドなのでマウスとかではない)のときの挙動.
	//if()
}

/// <summary>
/// 描画関数、オーバーライド関数.
/// </summary>
void Button::Draw()
{
	DrawGraph((int)mPos.x, (int)mPos.y, mImgHandle, true);
}
