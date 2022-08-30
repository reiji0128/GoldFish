#include "Background.h"
#include <DxLib.h>

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Background::Background(const char* fileName)
	:mPos(Vector2::Zero)
	,mScale(Vector2::Zero)
	,mImgHandle(-1)
{
	// �摜�n���h���̎擾.
	mImgHandle = LoadGraph(fileName);

	// �摜�̑傫���̎擾.
	GetGraphSizeF(mImgHandle, &mScale.x, &mScale.y);
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Background::~Background()
{
	// ���ɉ摜�n���h����-1�̎���return��Ԃ�.
	if (mImgHandle == -1)
	{
		return;
	}
	// �摜���������ォ��폜����.
	DeleteGraph(mImgHandle);
	// �폜�������-1����͂��Ă���.
	mImgHandle = -1;
}

/// <summary>
/// �X�V�֐�.
/// </summary>
void Background::Update()
{
}

/// <summary>
/// �`��֐�.
/// </summary>
void Background::Draw()
{
	// �`�揈��.
	DrawGraph(mPos.x, mPos.y, mImgHandle, true);
}