#pragma once
#include "Math.h"
#include "Background.h"
#include "UI.h"

// �R���X�^���g�ϐ�(static).
static const int MWidth = 1920;
static const int MHeight = 1080;

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
	virtual SceneBase::SceneTag Updata(float deltaTime) = 0;

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
	UI* ui;

	bool mChangeSceneFlag;               // �V�[���ړ��t���O�Atrue�̎��̓V�[����ς���false�̎��̓V�[����ς��Ȃ�.
	bool mGameExitFlag;                  // �Q�[���I���t���O�Atrue�̎��̓Q�[�����I��������false�̎��̓Q�[���𑱂���.
};