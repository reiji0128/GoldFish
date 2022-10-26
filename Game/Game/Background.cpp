#include "DxLib.h"
#include "Background.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="fileName">const char*�^�̉摜�t�@�C���p�X.</param>
Background::Background(const char* fileName)
	:Image(fileName)
{
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Background::~Background()
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

/// <summary>
/// �X�V�֐�.
/// </summary>
void Background::Updata(float deltaTime)
{
}