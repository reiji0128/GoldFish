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
	// ‚·‚Å‚É‰æ‘œƒnƒ“ƒhƒ‹‚ª-1‚Ì‚Íreturn‚ğ•Ô‚·
	if (mImgHandle == -1)
	{
		return;
	}

	// ‰æ‘œ‚ğƒƒ‚ƒŠã‚©‚çíœ‚·‚é.
	DeleteGraph(mImgHandle);

	// íœ‚µ‚½Œã‚É-1‚ğ‘ã“ü‚·‚é.
	mImgHandle = -1;
}

void Button::Update(float deltaTime)
{
}

void Button::Draw()
{
	DrawGraph(mPos.x, mPos.y, mImgHandle, true);
}
