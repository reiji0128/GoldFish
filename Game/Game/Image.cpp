#include "Image.h"
#include "DxLib.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="fileName">const char*�^�̃t�@�C���p�X.</param>
Image::Image(const char* fileName)
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
Image::~Image()
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
