#include "Title.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Title::Title()
{
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Title::~Title()
{
}

/// <summary>
/// �X�V�֐�.
/// </summary>
/// <param name="deltaTime">float�^�̃f���^�^�C���̈���.</param>
/// <returns>SCENE_TAG�^��enum�N���X��Ԃ�.</returns>
SCENE_TAG Title::Update(float deltaTime)
{
	// Background�N���X�̍X�V�֐����s��.
	mBg->Update();

	// �{�^���������ꂽ�Ƃ��Ƀv���C�V�[���ֈڍs���鏈��@@@

	// ����ȊO�̏ꍇ�͂��̃V�[����Ԃ�.
	return SCENE_TAG::NONE_TAG;
}

/// <summary>
/// �`��֐�.
/// </summary>
void Title::Draw()
{
	// �^�C�g���V�[���̔w�i��`��.
	mBg->Draw();
}