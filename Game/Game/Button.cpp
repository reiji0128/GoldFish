#include "Button.h"
#include "DxLib.h"

Button::Button(const char* fileName)
	:mPos(Vector2::Zero)
	,mScale(Vector2::Zero)
	,mImgHandle(-1)
{
	mImgHandle = LoadGraph(fileName);

	GetGraphSizeF(mImgHandle, &mScale.x, &mScale.y);
}

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

void Button::Update(float deltaTime)
{
	// オンマウス？(ぶっちゃけパッドなのでマウスとかではない)のときの挙動.
	//if()
}

void Button::Draw()
{
	DrawGraph(mPos.x, mPos.y, mImgHandle, true);
}
