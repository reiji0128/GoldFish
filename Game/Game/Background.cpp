#include "Background.h"
#include <DxLib.h>

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Background::Background()
	:mPos(Vector2::Zero)
	,mWidth(0)
	,mHeight(0)
	,mImgHandle(-1)
{
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
/// �ǂݍ��݊֐�.
/// </summary>
/// <param name="imgName">char*�^�̉摜�̃t�@�C���p�X.</param>
void Background::Load(const char* imgName)
{
	// �摜�ǂݍ���.
	mImgHandle = LoadGraph(imgName);

	// �摜�T�C�Y�̎擾.
	GetGraphSize(mImgHandle, &mWidth, &mHeight);
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