#include "SceneBase.h"

// ���݂̃V�[���̏�����.
SceneBase::SceneTag SceneBase::mNowSceneTag =
SceneTag::INIT_TAG;

/// <summary>
/// �R���X�g���N�^.
/// </summary>
SceneBase::SceneBase(SceneTag nowTag)
	:mChangeSceneFlag(false)
	,mBg(nullptr)
{
	// �V�[���^�O�̍X�V.
	mNowSceneTag = nowTag;
}