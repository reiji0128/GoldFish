#pragma once
#include "Math.h"

/// <summary>
/// ���ꂼ��V�[���̃^�O.
/// </summary>
enum SCENE_TAG
{
	NONE_TAG = 0,
	TITLE_TAG,
	PLAY_TAG,
	RESULT_TAG,
};

/// <summary>
/// SceneBase�N���X.
/// </summary>
class SceneBase
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	SceneBase();

	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	virtual ~SceneBase();

	/// <summary>
	/// �X�V�֐��A���z�֐�.
	/// </summary>
	/// <returns>enum��SCENE_TAG��Ԃ�.</returns>
	virtual SCENE_TAG Update() = 0;

	/// <summary>
	/// �`��֐��A���z�֐�.
	/// </summary>
	virtual void Draw() = 0;

protected:
};