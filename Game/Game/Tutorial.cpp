#include "Tutorial.h"
#include "DxLib.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Tutorial::Tutorial()
     // SceneBase�N���X�̃R���X�g���N�^�ASceneTag��TutorialTag�ɂ���.
    :SceneBase(SceneBase::SceneTag::TutorialTag)
    // �����������Ƃ��̒l�̍ő�l�̏�����.
    ,MCOUNT_MAX(200.0f)
    // �`���[�g���A���X�L�b�v�{�^���̏�����.
    ,mTutorialSkipBtn(nullptr)
    // �������������̂ݑ�������ϐ��̏�����.
    ,mCount(0.0f)
    // �V�[�����ɃI���}�E�X���Ă���{�^���̃X�e�[�^�X��ۑ�����ϐ��̏�����.
    ,mNowOnBtn(BtnState::None)
{
    // Background�N���X�̃R���X�g���N�^�A�����Ƀ^�C�g���摜���w�肷��.
    mBg = new Background(BgImgName[BgImgFileNum::PlayBg]);

    // Button�N���X�̃R���X�g���N�^�A�����Ƀ{�^���摜�ƃX�e�[�^�X���w�肷��.
    mTutorialSkipBtn = new Button(ButtonImgName[ButtonImgFileNum::TutorialSkip],BtnState::TutoSkip);

    // Button�N���X�̍��W�ݒ�.
    mTutorialSkipBtn->SetPosition(Vector2((mTutorialSkipBtn->GetScale().x / 2) + 50, (mTutorialSkipBtn->GetScale().y / 2) + 50));
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Tutorial::~Tutorial()
{
    // �������폜.
    delete mBg;
    delete mTutorialSkipBtn;

    // �������̏�����.
    mBg = nullptr;
    mTutorialSkipBtn = nullptr;
}

/// <summary>
/// �X�V�֐��A�I�[�o�[���C�h�֐�.
/// </summary>
/// <param name="deltaTime">float�^�̃f���^�^�C��.</param>
/// <returns>SceneTag�^��enum�N���X��Ԃ�.</returns>
SceneBase::SceneTag Tutorial::Updata(float deltaTime)
{
    // ���͏���.
    Input();

    // Button�N���X�̍X�V�֐�.
    mTutorialSkipBtn->Updata(deltaTime, ViewState::CircleGauge);

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

    // ��ڂ�JoyPad��A�{�^���������Ă�����.
    if (pad1Input & PAD_INPUT_1)
    {
        // �������ϐ��𑝉�����
        mCount += mTutorialSkipBtn->GetCirclePercentAdd();

        // �Q�[�W��\�����邽�߂Ƀt���O��true�ɂ���.
        mTutorialSkipBtn->SetCircleFlag(true);

        // �������J�E���g������l�𒴂�����.
        if (mCount > MCOUNT_MAX)
        {
            // �Q�[�W�𑝂₷�t���O��false�ɂ���.
            mTutorialSkipBtn->SetCircleFlag(false);

            // �v���C�V�[����Ԃ�.
            mChangeSceneFlag = true;
        }
    }
    // ����ȊO�̎�.
    else
    {
        // �J�E���g���O�ɖ߂�.
        mCount = 0;

        // �Q�[�W���ŏ�����ɂ���.
        mTutorialSkipBtn->SetCirclePercent(0.0f);

        // �Q�[�W�𑝂₷�t���O��false�ɂ���.
        mTutorialSkipBtn->SetCircleFlag(false);
    }

    // �܂��̓f�o�b�O�p�Ƃ��ăL�[�{�[�h�łW�{�^�����������Ƃ�.
    if (CheckHitKey(KEY_INPUT_8))
    {
        // �V�[����ς���t���O��true�ɂ���.
        mChangeSceneFlag = true;
    }
}
