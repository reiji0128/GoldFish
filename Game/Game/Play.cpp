#include "Play.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Play::Play()
	:gameManager(nullptr)// gameManager�̏�����.
{
	// gameManager�̃R���X�g���N�^.
	gameManager = new GameManager();
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Play::~Play()
{
	delete gameManager;
}

/// <summary>
/// �X�V�֐�.
/// </summary>
/// <param name="deltaTime">float�^�̃f���^�^�C���̈���.</param>
/// <returns>SCENE_TAG�^��enum�N���X��Ԃ�.</returns>
SCENE_TAG Play::Update(float deltaTime)
{
	//gameManager->Update();

	// ����̏����Ń��U���g�V�[�����ڍs���鏈��@@@

	// ����ȊO�̏ꍇ�͂��̃V�[����Ԃ�.
	return SCENE_TAG::NONE_TAG;
}

/// <summary>
/// �`��֐�.
/// </summary>
void Play::Draw()
{
}