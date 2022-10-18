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
		TutorialTag,         // �V�[�����`���[�g���A���̎�.
		PlayTag,             // �V�[�����v���C�̎�.
		ResultTag,           // �V�[�������U���g�̎�.
		ExitTag,             // �V�[�������鎞.
	};

	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="nowTag">SceneTag�^�̈���.</param>
	SceneBase(SceneTag nowTag);

	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~SceneBase() {};

	/// <summary>
	/// �X�V�֐��A���z�֐�.
	/// </summary>
	/// <param name="delteTime">float�^�̃f���^�^�C���̈���.</param>
	/// <returns>SceneTag�^��enum�N���X��Ԃ�.</returns>
	virtual SceneBase::SceneTag Updata() = 0;

	/// <summary>
	/// ���͏����֐��A���z�֐�.
	/// </summary>
	virtual SceneTag Input() = 0;

	/// <summary>
	/// �`��֐��A���z�֐�.
	/// </summary>
	virtual void Draw() = 0;

	static SceneTag mNowSceneTag;        // ���݂̃V�[���^�O.

protected:
	Background* mBg;                     // �w�i�̐���.
	bool mChangeSceneFlag;               // �V�[���ړ��t���O.
};