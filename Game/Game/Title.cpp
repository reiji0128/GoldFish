#include "Title.h"
#include "DxLib.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Title::Title()
	// SceneBase�N���X�̃R���X�g���N�^�ASceneTag��TitleTag�ɂ���.
	:SceneBase(SceneBase::SceneTag::TitleTag)
	// �X�^�[�g�{�^���̏�����.
	,mStartBtn(nullptr)
	// �Q�[�������{�^���̏�����.
	,mExitBtn(nullptr)
{
	// Background�N���X�̃R���X�g���N�^�A�����Ƀ^�C�g����Background���w�肷��.
	mBg = new Background(BgImgName[BgImgFileNum::TitleBg]);

	// Button�N���X�̃R���X�g���N�^.
	mStartBtn = new Button(ButtonImgName[ButtonImgFileNum::StartBtn]);
	mExitBtn = new Button(ButtonImgName[ButtonImgFileNum::ExitBtn]);

}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Title::~Title()
{
	// �������̍폜.
	delete mBg;
	delete mStartBtn;
	delete mExitBtn;
}

/// <summary>
/// �X�V�֐�.
/// </summary>
/// <returns>SceneTag�^��enum�N���X��Ԃ�.</returns>
SceneBase::SceneTag Title::Updata()
{
	// ���͏���.
	return Input();
}

/// <summary>
/// �`�揈��.
/// </summary>
void Title::Draw()
{
	// Background�N���X�̕`�揈��.
	mBg->Draw();

	mStartBtn->Draw();
	mExitBtn->Draw();
}

/// <summary>
/// �V�[����ς���ۂ̓��͏����֐�.
/// </summary>
SceneBase::SceneTag Title::Input()
{
	// ���݂̃p�b�h�̉������{�^���̓��͏�Ԃ�ۑ�����ϐ�.
	int pad1Input;

	// �P�ڂ�JoyPad�̉������{�^���̓��͏�Ԃ��擾.
	pad1Input = GetJoypadInputState(DX_INPUT_PAD1);

	// �P�ڂ�JoyPad��A�{�^���������Ă�����.
	// �f�o�b�O�p�Ƃ��ăL�[�{�[�h��7�{�^������������.
	if (pad1Input & PAD_INPUT_1
		|| CheckHitKey(KEY_INPUT_7))
	{
		// �����{�^���̃X�e�[�^�X��Start��������.
		if (mNowBtnState == btnState::Start)
		{
			// �`���[�g���A���V�[����Ԃ�.
			return SceneTag::TutorialTag;
		}
		// �����{�^���̃X�e�[�^�X��Exit��������.
		else if(mNowBtnState == btnState::Exit)
		{
			// �Q�[�������V�[���^�O��Ԃ�.
			return SceneTag::ExitTag;
		}
	}

	// ����ȊO�͎����̃V�[����Ԃ�.
	return mNowSceneTag;
}