#include "Tutorial.h"
#include "DxLib.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Tutorial::Tutorial()
     // SceneBase�N���X�̃R���X�g���N�^�ASceneTag��TutorialTag�ɂ���.
    :SceneBase(SceneBase::SceneTag::TutorialTag)
{
    // Background�N���X�̃R���X�g���N�^�A�����Ƀ^�C�g����Background���w�肷��.
    mBg = new Background(BgImgName[BgImgFileNum::TutorialBg]);
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Tutorial::~Tutorial()
{
}

/// <summary>
/// �X�V�֐�.
/// </summary>
/// <returns>SceneTag�^��enum�N���X��Ԃ�.</returns>
SceneBase::SceneTag Tutorial::Update()
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

    // ��ڂ�JoyPad��A�{�^���������Ă�����
    // �܂��̓f�o�b�O�p�Ƃ��ăL�[�{�[�h�łW�{�^�����������Ƃ�.
    if (pad1Input & PAD_INPUT_1
        || CheckHitKey(KEY_INPUT_8))
    {
        // �V�[����ς���t���O��true�ɂ���.
        mChangeSceneFlag = true;
    }
}
