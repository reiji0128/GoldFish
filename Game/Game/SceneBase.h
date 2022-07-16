#pragma once
#include "Math.h"
#include "Background.h"

/// <summary>
/// ���ꂼ��V�[���̃^�O.
/// </summary>
enum class SCENE_TAG : short
{
	NONE_TAG = 0,         // �V�[���������̎�.
	TITLE_TAG,            // �V�[�����^�C�g���̎�.
	PLAY_TAG,             // �V�[�����v���C�̎�.
	RESULT_TAG,           // �V�[�������U���g�̎�.
};

/// <summary>
/// �V�[���̊��N���X.
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
	Background* mBg;      // �w�i�N���X��ۑ�����ϐ�.
};