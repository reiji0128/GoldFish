#include "SceneBase.h"

// ���݂̃V�[���̏�����.
SceneBase::SceneTag SceneBase::mNowSceneTag =
SceneTag::InitTag;

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="nowTag">���݂̃V�[���^�O�AenumClass�^�ϐ�.</param>
SceneBase::SceneBase(SceneTag nowTag)
	:mChangeSceneFlag(false)         // �V�[����ς��邩�ǂ����̃t���O�̏�����.
	,mGameExitFlag(false)            // �Q�[�����I�������邩�ǂ����̃t���O�̏�����.
	,mBg(nullptr)                    // Background�N���X�̏�����.
{
	// �V�[���^�O�̍X�V.
	mNowSceneTag = nowTag;
}