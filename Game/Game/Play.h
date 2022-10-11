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
	/// �X�V�����A�I�[�o�[���C�h�֐�.
	/// </summary>
	/// <returns>SceneBase��enumClass�ł���SceneTag�^��Ԃ�.</returns>
	SceneTag Update() override;

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