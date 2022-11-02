#pragma once
#include "SceneBase.h"
#include "Button.h"

/// <summary>
/// �V�[���̃^�C�g���N���X.
/// SceneBase���p�����Ă���.
/// </summary>
class Title : public SceneBase
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	Title();

	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~Title();

	/// <summary>
	/// �X�V�֐��A�I�[�o�[���C�h�֐�.
	/// </summary>
	/// <param name="deltaTime">float�^�̃f���^�^�C��.</param>
	/// <returns>SceneTag�^��enum�N���X��Ԃ�.</returns>
	SceneTag Updata(float deltaTime) override;

	/// <summary>
	/// �`�揈���A�I�[�o�[���C�h�֐�.
	/// </summary>
	void Draw() override;

	/// <summary>
	/// ���͏����֐��A�I�[�o�[���C�h�֐�.
	/// </summary>
	void Input() override;

private:
	Button* mStartBtn;               // �`���[�g���A���Ɉڍs����Button�N���X�̕ϐ�.
	Button* mExitBtn;                // �Q�[�������Button�N���X�̕ϐ�.

	BtnState mNowOnBtn;              // ���݃I���}�E�X���Ă���{�^���̃X�e�[�^�X���擾����.
};