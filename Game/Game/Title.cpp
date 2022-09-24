#include "Title.h"
#include "DxLib.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Title::Title()
	// SceneBase�N���X�̃R���X�g���N�^�ASceneTag��TitleTag�ɂ���.
	:SceneBase(SceneBase::SceneTag::TitleTag)
	//,mStartButton(nullptr)
	//,mExitButton(nullptr)
	//,mStartFlag(false)
{
	// Background�N���X�̃R���X�g���N�^�A�����Ƀ^�C�g����Background���w�肷��.
	mBg = new Background(BgImgName[BgImgFileNum::TitleBg]);

	//mStartButton = new Button(ButtonImgName[ButtonImgFileNum::START_BUTTON_IMG]);
	//mExitButton = new Button(ButtonImgName[ButtonImgFileNum::EXIT_BUTTON_IMG]);
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Title::~Title()
{
}

/// <summary>
/// �X�V�֐�.
/// </summary>
/// <returns>SceneTag�^��enum�N���X��Ԃ�.</returns>
SceneBase::SceneTag Title::Update()
{
	// mChangeSceneFlag��true��������.
	if (mChangeSceneFlag)
	{
		// PlayTag��Ԃ�.
		return SceneTag::PlayTag;
	}

	// ���݂̃V�[���^�O��Ԃ�.
	return mNowSceneTag;
}

/// <summary>
/// �`�揈��.
/// </summary>
void Title::Draw()
{
	// Background�N���X�̕`�揈��.
	mBg->Draw();
}

/// <summary>
/// ���͏����֐��A�I�[�o�[���C�h�֐�.
/// </summary>
void Title::Input()
{
	// ���݂̃p�b�h�̉������{�^���̓��͏�Ԃ�ۑ�����ϐ�.
	int pad1Input;

	// �P�ڂ�JoyPad�̉������{�^���̓��͏�Ԃ��擾.
	pad1Input = GetJoypadInputState(DX_INPUT_PAD1);

	// �P�ڂ�JoyPad��A�{�^���������Ă�����.
	// �f�o�b�N�p�Ƃ��ăL�[�{�[�h��8�{�^������������.
	if (pad1Input & PAD_INPUT_1
		|| CheckHitKey(KEY_INPUT_8))
	{
		// �V�[����ς���t���O��true�ɂ���.
		mChangeSceneFlag = true;
	}
}