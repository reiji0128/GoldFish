#pragma once
#include "SceneBase.h"
#include <DxLib.h>

/// <summary>
/// �V�[���̃}�l�[�W���[�N���X.
/// </summary>
class SceneManager
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	SceneManager();

	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~SceneManager();

	/// <summary>
	/// �Q�[�����[�v�֐�.
	/// </summary>
	void GameRoop();

	/// <summary>
	/// �V�[������.
	/// </summary>
	/// <param name="sceneTag">���̃V�[���𔻒肷��Ƃ���enum class�^�̃^�O.</param>
	void CreatsScene(SCENE_TAG sceneTag);

	/// <summary>
	/// �V�[���̍폜.
	/// </summary>
	void ClearScene();

private:
	SceneBase* mNowScene;        // ���݂̃V�[����ۑ�����ϐ�.
};

