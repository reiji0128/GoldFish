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
	/// �X�V�֐�.
	/// �I�[�o�[���C�h�֐�.
	/// </summary>
	/// <returns>enum class�^��SCENE_TAG��Ԃ�.</returns>
	SCENE_TAG Update() override;

	/// <summary>
	/// �`��֐�.
	/// �I�[�o�[���C�h�֐�.
	/// </summary>
	void Draw() override;

private:
};