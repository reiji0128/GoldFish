#include "Result.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Result::Result()
{
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Result::~Result()
{
}

/// <summary>
/// �X�V�֐�.
/// </summary>
/// <param name="deltaTime">float�^�̃f���^�^�C���̈���.</param>
/// <returns>SCENE_TAG�^��enum�N���X��Ԃ�.</returns>
SCENE_TAG Result::Update(float deltaTime)
{
	// �^�C�g���V�[���ւ̈ڍs����.@@@

	// �Q�[���I������.@@@

	// ����ȊO�͂��̃V�[����Ԃ�.
	return SCENE_TAG::NONE_TAG;
}

/// <summary>
/// �`��֐�.
/// </summary>
void Result::Draw()
{
	// �w�i�̕`�揈��.
	mBg->Draw();
}