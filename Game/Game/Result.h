#pragma once
#include "SceneBase.h"

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
	/// �X�V�֐�.
	/// </summary>
	/// <param name="deltaTime">float�^�̃f���^�^�C���̈���.</param>
	/// <returns>SCENE_TAG�^��enum�N���X��Ԃ�.</returns>
	SCENE_TAG Update(float deltaTime);

	/// <summary>
	/// �`��֐�.
	/// </summary>
	void Draw();

private:
};

