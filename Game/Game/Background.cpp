#include "DxLib.h"
#include "Background.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Background::Background(const char* fileName)
	:mPos(Vector2::Zero)
	,mScale(Vector2::Zero)
	,mVec(Vector2::Zero)
	,mMoveFlag(false)
	,mImgHandle(-1)
{
	mImgHandle = LoadGraph(fileName);

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
	if (mMoveFlag)
	{
		mPos += mVec;
	}
}

/// <summary>
/// �`��֐�.
/// </summary>
void Background::Draw()
{
	// �`�揈��.
	DrawGraph(mPos.x, mPos.y, mImgHandle, true);
}