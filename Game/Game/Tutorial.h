#pragma once
#include "SceneBase.h"

/// <summary>
/// �V�[���̃`���[�g���A���N���X.
/// SceneBase���p�����Ă���.
/// </summary>
class Tutorial : public SceneBase
{
public :
    /// <summary>
    /// �R���X�g���N�^.
    /// </summary>
    Tutorial();

    /// <summary>
    /// �f�X�g���N�^.
    /// </summary>
    ~Tutorial();

    /// <summary>
    /// �X�V�֐��A�I�[�o�[���C�h�֐�.
    /// </summary>
    /// <returns>SceneTag�^��enum�N���X��Ԃ�.</returns>
    SceneTag Update() override;

    /// <summary>
    /// �`�揈��.
    /// </summary>
    void Draw() override;

    /// <summary>
    /// ���͏����֐��A�I�[�o�[���C�h�֐�.
    /// </summary>
    void Input() override;

private:

};

