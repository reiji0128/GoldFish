#include "Play.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Play::Play()
{
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Play::~Play()
{
}

/// <summary>
/// �X�V�֐�.
/// </summary>
/// <param name="deltaTime">float�^�̃f���^�^�C���̈���.</param>
/// <returns>SCENE_TAG�^��enum�N���X��Ԃ�.</returns>
SCENE_TAG Play::Update(float deltaTime)
{
	// Background�N���X�̍X�V�֐����s��.
	mBg->Update();

	// ����̏����Ń��U���g�V�[�����ڍs���鏈��@@@

	// ����ȊO�̏ꍇ�͂��̃V�[����Ԃ�.
	return SCENE_TAG::NONE_TAG;
}

/// <summary>
/// �`��֐�.
/// </summary>
void Play::Draw()
{
	// �v���C�V�[���̔w�i��`��.
	mBg->Draw();
}