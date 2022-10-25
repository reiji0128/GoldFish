#include "Button.h"
#include "DxLib.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="fileName">const char*�^�̉摜�t�@�C���p�X.</param>
Button::Button(const char* fileName, BtnState state)
	// �摜�N���X�̏�����������.
	:Image(fileName)
	// ���������ǂ����̃t���O�̏�����.
	,mPushBtnFlag(false)
	// ���̃{�^���̎����Ă���X�e�[�^�X�̏�����.
	,mState(BtnState::None)
{
	// �X�e�[�^�X�̑��.
	mState = state;
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
}

/// <summary>
/// ���͏����֐�.
/// </summary>
/// <param name="state">BtnState�̕ϐ�.</param>
void Button::Input(BtnState state)
{
	if (state == BtnState::Start)
	{
		mChangeSceneFlag = true;
	}
	else if (state == BtnState::Exit)
	{
		mGameExitFlag = true;
	}
}

/// <summary>
/// �`��֐��A�I�[�o�[���C�h�֐�.
/// </summary>
void Button::Draw()
{
	DrawGraph((int)mPos.x, (int)mPos.y, mImgHandle, true);
}
