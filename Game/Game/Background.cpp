#include "DxLib.h"
#include "Background.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="fileName">const char*�^(������^)�̃t�@�C���p�X.</param>
Background::Background(const char* fileName)
	// ���W�ۑ��ϐ��̏�����.
	:mPos(Vector2::Zero)
	// �摜�T�C�Y�ۑ��ϐ��̏�����.
	,mScale(Vector2::Zero)
	// �摜�n���h���ۑ��ϐ��̏�����.
	,mImgHandle(-1)
{
	// �摜�n���h����ǂݍ���.
	mImgHandle = LoadGraph(fileName);

	// �摜�n���h���̃T�C�Y�̎擾.
	GetGraphSizeF(mImgHandle, &mScale.x, &mScale.y);
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