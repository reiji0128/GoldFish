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
    /// <param name="deltaTime">float�^�̃f���^�^�C��.</param>
    /// <returns>SceneTag�^��enum�N���X��Ԃ�.</returns>
    SceneTag Updata(float deltaTime) override;

    /// <summary>
    /// �`�揈��.
    /// </summary>
    void Draw() override;

    /// <summary>
    /// ���͏����֐��A�I�[�o�[���C�h�֐�.
    /// </summary>
    void Input() override;

    const double MCOUNT_MAX;                   // �����������Ƃ��ɑ�����������l�̍ő�l.

private:
    Button* mTutorialSkipBtn;                  // �`���[�g���A�����X�L�b�v����Button�N���X�̕ϐ�.
    BtnState mNowOnBtn;                        // ���̃V�[�����ɃI���}�E�X��Ԃɂ���{�^���̃X�e�[�^�X.

    double mCount;                             // �������������̂ݑ�������J�E���^�[.
};