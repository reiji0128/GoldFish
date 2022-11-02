#pragma once
#include "SceneBase.h"
#include "Button.h"

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
	Button* mTitleBtn;            // �^�C�g���Ɉڍs����Button�N���X�̕ϐ�.
	Button* mExitBtn;             // �Q�[�������Button�N���X�̕ϐ�.

	BtnState mNowOnBtn;           // ���݃I���}�E�X��Ԃɂ���{�^���̃X�e�[�^�X���擾����.
};