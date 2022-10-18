#pragma once
#include "SceneBase.h"
#include "Background.h"

/// <summary>
/// �V�[���̃��U���g�N���X.
/// SceneBase���p�����Ă���.
/// </summary>
class Result :public SceneBase
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	Result();

	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~Result();

	/// <summary>
	/// �X�V�֐��A�I�[�o�[���C�h�֐�.
	/// </summary>
	/// <param name="deltaTime">float�^�̃f���^�^�C���̈���.</param>
	/// <returns>SCENE_TAG�^��enum�N���X��Ԃ�.</returns>
	SceneTag Updata() override;

	/// <summary>
	/// �`��֐��A�I�[�o�[���C�h�֐�.
	/// </summary>
	void Draw() override;

	/// <summary>
	/// ���͏����֐��A�I�[�o�[���C�h�֐�.
	/// </summary>
	void Input() override;

private:
};

