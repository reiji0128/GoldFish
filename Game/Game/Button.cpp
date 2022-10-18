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
/// �f�X�g���N�^.
/// </summary>
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

/// <summary>
/// �X�V�֐��A�I�[�o�[���C�h�֐�.
/// </summary>
/// <param name="deltaTime"></param>
void Button::Updata(float deltaTime)
{
	// �I���}�E�X�H(�Ԃ����Ⴏ�p�b�h�Ȃ̂Ń}�E�X�Ƃ��ł͂Ȃ�)�̂Ƃ��̋���.
	//if()
}

/// <summary>
/// �`��֐��A�I�[�o�[���C�h�֐�.
/// </summary>
void Button::Draw()
{
	DrawGraph((int)mPos.x, (int)mPos.y, mImgHandle, true);
}
