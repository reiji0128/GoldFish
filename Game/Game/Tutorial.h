#pragma once
#include "SceneBase.h"
#include "Button.h"

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
    SceneTag Updata() override;

    /// <summary>
    /// �`�揈��.
    /// </summary>
    void Draw() override;

    /// <summary>
    /// ���͏����֐��A�I�[�o�[���C�h�֐�.
    /// </summary>
    void Input() override;

    const int MCOUNT_MAX;                      // �����������Ƃ��ɑ�����������l�̍ő�l.

private:
    BtnState mNowOnBtn;                        // ���̃V�[�����ɃI���}�E�X��Ԃɂ���{�^���̃X�e�[�^�X.
    Button* mTutorialSkipBtn;                  // �`���[�g���A�����X�L�b�v����Button�N���X�̕ϐ�.
    int mCount;                                // �������������̂ݑ�������J�E���^�[.
};