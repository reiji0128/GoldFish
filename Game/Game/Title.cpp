#include "Title.h"
#include "DxLib.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Title::Title()
	:SceneBase(SceneBase::SceneTag::TITLE_TAG)
	,mStartButton(nullptr)
	,mExitButton(nullptr)
	,mStartFlag(false)
{
	mBg = new Background(BgImgName[BgImgFileNum::TITLE_IMG]);

	mStartButton = new Button(ButtonImgName[ButtonImgFileNum::START_BUTTON_IMG]);
	mExitButton = new Button(ButtonImgName[ButtonImgFileNum::EXIT_BUTTON_IMG]);
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
/// <param name="deltaTime">float�^�̃f���^�^�C���̈���.</param>
/// <returns>SceneTag�^��enum�N���X��Ԃ�.</returns>
SceneBase::SceneTag Title::Update()
{
	if (mChangeSceneFlag)
	{
		return SceneTag::PLAY_TAG;
	}

	return mNowSceneTag;
}

void Title::Draw()
{
	mBg->Draw();
}

/// <summary>
/// ���͏����֐��A�I�[�o�[���C�h�֐�.
/// </summary>
void Title::Input()
{
	int pad1Input;
	pad1Input = GetJoypadInputState(DX_INPUT_PAD1);

	if (pad1Input & PAD_INPUT_1)
	{
		// �V�[����ς���t���O��true�ɂ���.
		mChangeSceneFlag = true;
	}
	else
	{
		mChangeSceneFlag = false;
	}
}