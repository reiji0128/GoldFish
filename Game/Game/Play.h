#pragma once
#include "SceneBase.h"

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
	/// <param name="deltaTime">float�^�̃f���^�^�C��.</param>
	/// <returns>SceneTag�^��enum�N���X��Ԃ�.</returns>
	SceneTag Updata(float deltaTime) override;

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