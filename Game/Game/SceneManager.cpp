#include "SceneManager.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
SceneManager::SceneManager()
{
	// �V�[���𐶐�.
	CreatsScene(SCENE_TAG::TITLE_TAG);

	/// <summary>
	/// �Q�[�����[�v�Ɉڍs.
	/// </summary>
	GameRoop();
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
SceneManager::~SceneManager()
{
}

/// <summary>
/// �Q�[�����[�v�֐�.
/// </summary>
void SceneManager::GameRoop()
{
	// �G�X�P�[�v�L�[��������Ȃ��ԁAwhile���܂킷.
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// �E�B���h�E�̃��b�Z�[�W���G���[���o�����Ƃ��Q�[�����[�v���I������.
		if (ProcessMessage())
		{
			break;
		}

		//// ���݂̃V�[���^�O��ۑ�����.@@@
		//SCENE_TAG tag = mNowScene->Update();

		// ------------�`�揈��-------------- //
		ClearDrawScreen();

		// ���݂̃V�[����`��.
		mNowScene->Draw();

		ScreenFlip();

		//// �V�[���^�O�������̎��͈ȉ��̏����͎��s���Ȃ�.@@@
		//if (tag == SCENE_TAG::NONE_TAG)
		//{
		//	continue;
		//}

		// �V�[���̍폜.@@@
		ClearScene();

		//// �V�[���̐���.@@@
		//CreatsScene(tag);
	}
}

/// <summary>
/// �V�[���̐����֐�.
/// </summary>
/// <param name="sceneTag">���̃V�[����ۑ�����enum class�^�ϐ�.</param>
void SceneManager::CreatsScene(SCENE_TAG sceneTag)
{
	if (sceneTag == SCENE_TAG::TITLE_TAG)
	{
		// @@@
	}
	else if (sceneTag == SCENE_TAG::PLAY_TAG)
	{
		// @@@
	}
	else if (sceneTag == SCENE_TAG::RESULT_TAG)
	{
		// @@@
	}
}

/// <summary>
/// �V�[���̍폜.
/// </summary>
void SceneManager::ClearScene()
{
	// ���݂̃V�[����nullptr�������Ă�����.
	if (mNowScene == nullptr)
	{
		// �������Ȃ�.
	}
	// ����nullptr�ȊO�̕��������Ă�����.
	// ��������V�[���̃|�C���^�[�������Ă�����.
	else
	{
		// ���݂̃V�[�����폜����.
		delete mNowScene;

		// �ϐ���nullptr����.
		mNowScene = nullptr;
	}
}
