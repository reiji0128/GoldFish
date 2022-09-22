#pragma once
#include "SceneBase.h"
#include "Background.h"
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
	/// <returns>SCENE_TAG�^��enum�N���X��Ԃ�.</returns>
	SceneTag Update() override;

	/// <summary>
	/// �`�揈��.
	/// </summary>
	void Draw() override;

	/// <summary>
	/// ���͏����֐��A�I�[�o�[���C�h�֐�.
	/// </summary>
	void Input() override;

private:
	Button* mStartButton;
	Button* mExitButton;

	bool mStartFlag;
};