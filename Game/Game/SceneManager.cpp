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
		if (ProcessMessage())
		{
			break;
		}
	}
}

void SceneManager::CreatsScene(SCENE_TAG sceneTag)
{
}

void SceneManager::ClearScene()
{
}
