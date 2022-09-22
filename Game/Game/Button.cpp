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
	// ���łɉ摜�n���h����-1�̎���return��Ԃ�
	if (mImgHandle == -1)
	{
		return;
	}

	// �摜���������ォ��폜����.
	DeleteGraph(mImgHandle);

	// �폜�������-1��������.
	mImgHandle = -1;
}

void Button::Update(float deltaTime)
{
	// �I���}�E�X�H(�Ԃ����Ⴏ�p�b�h�Ȃ̂Ń}�E�X�Ƃ��ł͂Ȃ�)�̂Ƃ��̋���.
	//if()
}

void Button::Draw()
{
	DrawGraph(mPos.x, mPos.y, mImgHandle, true);
}
