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
	/// <param name="deltaTime">float�^�̃f���^�^�C���̈���.</param>
	/// <returns>SceneTag�^��enum�N���X��Ԃ�.</returns>
	SceneTag Updata() override;

	/// <summary>
	/// �`�揈���A�I�[�o�[���C�h�֐�.
	/// </summary>
	void Draw() override;

	/// <summary>
	/// ���͏����֐��A�I�[�o�[���C�h�֐�.
	/// </summary>
	SceneTag Input() override;

private:
	/// <summary>
	/// �{�^���̃X�e�[�^�X.
	/// �����Ă���l�̌^��unsigned short.
	/// </summary>
	enum class btnState : unsigned short
	{
		Start = 1,                   // Joypad���X�^�[�g�{�^�����I���}�E�X��Ԃɂ���Ƃ�.
		Exit,                        // Joypad���Ƃ���{�^�����I���}�E�X��Ԃɂ���Ƃ�.
	};

	Button* mStartBtn;               // �`���[�g���A���Ɉڍs����Button�N���X�̕ϐ�.
	Button* mExitBtn;                // �Q�[�������Button�N���X�̕ϐ�.
	btnState mNowBtnState;           // ��Joypad���I���}�E�X��Ԃɂ���X�e�[�^�X�̒l��ۑ�����ϐ�.
};