#include "Tutorial.h"
#include "DxLib.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Tutorial::Tutorial()
     // SceneBase�N���X�̃R���X�g���N�^�ASceneTag��TutorialTag�ɂ���.
    :SceneBase(SceneBase::SceneTag::TutorialTag)
    // �����������Ƃ��̒l�̍ő�l�̏�����.
    ,MCOUNT(100)
    // �`���[�g���A���X�L�b�v�{�^���̏�����.
    ,mTutorialSkipBtn(nullptr)
{
    // Background�N���X�̃R���X�g���N�^�A�����Ƀ^�C�g���摜���w�肷��.
    mBg = new Background(BgImgName[BgImgFileNum::TutorialBg]);

    // Button�N���X�̃R���X�g���N�^�A�����Ƀ{�^���摜�ƃX�e�[�^�X���w�肷��.
    mTutorialSkipBtn = new Button(ButtonImgName[ButtonImgFileNum::TutorialSkip],BtnState::TutoSkip);
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Tutorial::~Tutorial()
{
    // �������폜.
    delete mBg;
    delete mTutorialSkipBtn;
}

/// <summary>
/// �X�V�֐�.
/// </summary>
/// <returns>SceneTag�^��enum�N���X��Ԃ�.</returns>
SceneBase::SceneTag Tutorial::Updata()
{
    // mChangeSceneFlag��true��������.
    if (mChangeSceneFlag)
    {
        // PlayTag��Ԃ�(�v���C�V�[���ֈڍs).
        return SceneTag::PlayTag;
    }

    // ���݂̃V�[����Ԃ�.
    return mNowSceneTag;
}

/// <summary>
/// �`��֐�.
/// </summary>
void Tutorial::Draw()
{
    // Background�N���X�̕`�揈��.
    mBg->Draw();

    // Button�N���X�̕`�揈��.
    mTutorialSkipBtn->Draw();
}

/// <summary>
/// �V�[����ς���ۂ̓��͏����֐�.
/// </summary>
void Tutorial::Input()
{
    // ���݂̃p�b�h�̉������{�^���̓��͏�Ԃ�ۑ�����֐�.
    int pad1Input;

    // ��ڂ�JoyPad�̉������{�^���̓��͏����擾.
    pad1Input = GetJoypadInputState(DX_INPUT_PAD1);

    {
        if(pad1Input & PAD_INPUT_1
            && this->mNowBtnState)
    }

    // ��ڂ�JoyPad��A�{�^���������Ă�����
    // �܂��̓f�o�b�O�p�Ƃ��ăL�[�{�[�h�łW�{�^�����������Ƃ�.
    if (pad1Input & PAD_INPUT_1
        || CheckHitKey(KEY_INPUT_8))
    {
        // �V�[����ς���t���O��true�ɂ���.
        mChangeSceneFlag = true;
    }
}
