#pragma once
#include "SceneBase.h"
#include "GameManager.h"

/// <summary>
/// �V�[���̃v���C�N���X.
/// SceneBase���p�����Ă���.
/// </summary>
class Play : public SceneBase
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	Play();

	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~Play();

	/// <summary>
	/// �X�V�֐��A�I�[�o�[���C�h�֐�.
	/// </summary>
	/// <param name="deltaTime">float�^�̃f���^�^�C���̈���.</param>
	/// <returns>SCENE_TAG�^��enum�N���X��return�Ƃ��ĕԂ�.</returns>
	SCENE_TAG Update(float deltaTime) override;

	/// <summary>
	/// �`��֐��A�I�[�o�[���C�h�֐�.
	/// </summary>
	void Draw() override;

private:
	/// <summary>
	/// �Q�[���S�̂̏����������Ă���ϐ�.
	/// </summary>
	GameManager* gameManager;
};