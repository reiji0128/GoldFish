#include "Exit.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Exit::Exit()
    :SceneBase(SceneBase::SceneTag::ExitTag)
{
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Exit::~Exit()
{
}

/// <summary>
/// �X�V�֐�.
/// </summary>
/// <returns>SceneTag�^��enum�N���X�̕ϐ���Ԃ�</returns>
SceneBase::SceneTag Exit::Updata()
{
    // ���͏���.
    Input();

    // �I���V�[���^�O��Ԃ�.
    return SceneTag::ExitTag;
}

/// <summary>
/// �V�[����ς���ۂ̓��͏����֐�.
/// </summary>
void Exit::Input()
{
}

/// <summary>
/// �`�揈��.
/// </summary>
void Exit::Draw()
{
}
