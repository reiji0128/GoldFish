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
	/// �X�V�֐�.
	/// �I�[�o�[���C�h�֐�.
	/// </summary>
	/// <param name="deltaTime">float�^�̃f���^�^�C���������Ƃ��Đݒ肷��.</param>
	/// <returns></returns>
	SCENE_TAG Update(float deltaTime) override;
};