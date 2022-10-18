#pragma once
#include "Math.h"
#include "Background.h"

/// <summary>
/// �V�[���̊��N���X.
/// </summary>
class SceneBase
{
public:
	/// <summary>
	/// ���ꂼ��V�[���̃^�O.
	/// </summary>
	enum class SceneTag
	{
		NoneTag = 0,         // �V�[���������̎�.
		InitTag,             // �V�[����������Ԃ̎�.
		TitleTag,            // �V�[�����^�C�g���̎�.
		PlayTag,             // �V�[�����v���C�̎�.
		ResultTag,           // �V�[�������U���g�̎�.
	};

	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	SceneBase(SceneTag nowTag);

	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~SceneBase() {};

	/// <summary>
	/// �X�V�֐��A���z�֐�.
	/// </summary>
	/// <param name="delteTime">float�^�̃f���^�^�C���̈���.</param>
	/// <returns>SCENE_TAG�^��enum�N���X��Ԃ�.</returns>
	virtual SceneBase::SceneTag Update() = 0;

	/// <summary>
	/// ���͏����֐��A���z�֐�.
	/// </summary>
	virtual void Input() = 0;

	/// <summary>
	/// �`��֐��A���z�֐�.
	/// </summary>
	virtual void Draw() = 0;

	static SceneTag mNowSceneTag;        // ���݂̃V�[���^�O.

protected:
	Background* mBg;                     // �w�i�̐���.
	bool mChangeSceneFlag;               // �V�[���ړ��t���O.
};