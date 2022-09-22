#pragma once
#include "SceneBase.h"

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
	SCENE_TAG Update(float deltaTime) override;

	/// <summary>
	/// �`��֐�.
	/// �I�[�o�[���C�h�֐�.
	/// </summary>
	void Draw() override;

private:
	Background* mBg;

};