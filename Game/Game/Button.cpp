#include "Button.h"
#include "DxLib.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="fileName">const char*�^�̉摜�t�@�C���p�X.</param>
Button::Button(const char* fileName, BtnState state)
	// �摜�N���X�̏�����������.
	:Image(fileName)
	// ���̃{�^���̎����Ă���X�e�[�^�X�̏�����.
	,mState(BtnState::None)
	// �㉺�̐U�ꕝ�̑傫��.
	,mRad(0.0f)
	// �㉺�̐U���X�s�[�h.
	,M_SPEED(50.0f)
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
void Button::Updata(float deltaTime, ViewState state)
{
	// �ϐ��̑��.
	Image::mState = state;

	// �\���X�e�[�^�X���~�`�ɕ\������Ƃ�.
	if (Image::mState == ViewState::CircleGauge
		&& mCircleMoveFlag)
	{
		mCirclePercentAdd = MPercentAdd * deltaTime;

		// �~�`�̃Q�[�W��ۑ�����ϐ��̑��.
		mCirclePercent += mCirclePercentAdd;
	}
	// �\���X�e�[�^�X���{�^���̎�.
	else if (Image::mState == ViewState::Button)
	{
		mRad += 0.03f;

		mPos.y += Math::Cos(mRad) * M_SPEED *  deltaTime;
	}
}