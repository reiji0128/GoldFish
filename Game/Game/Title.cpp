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
	// ���݃I���}�E�X��Ԃɂ���{�^���̃X�e�[�^�X�̏�����.
	,mNowOnBtn(BtnState::None)
{
	// Background�N���X�̃R���X�g���N�^�A�����Ƀ^�C�g����Background���w�肷��.
	mBg = new Background(BgImgName[BgImgFileNum::TitleBg]);

	// Button�N���X�̃R���X�g���N�^.
	mStartBtn = new Button(ButtonImgName[ButtonImgFileNum::StartBtn],BtnState::Start);
	mExitBtn = new Button(ButtonImgName[ButtonImgFileNum::ExitBtn],BtnState::Exit);

	// Button�N���X�̍��W�ݒ�.@@@(��)
	mStartBtn->SetPosition(Vector2(100, 100));
	mExitBtn->SetPosition(Vector2(200, 200));

	// ���݃I���}�E�X��Ԃɂ���{�^���̃X�e�[�^�X����.
	mNowOnBtn = mStartBtn->GetBtnState();
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
	Input();

	// �V�[����ς���t���O��true�̎�.
	if (mChangeSceneFlag)
	{
		// �^�C�g���V�[���̃^�O��Ԃ�.
		return SceneTag::TutorialTag;
	}
	// �Q�[�����I��点��t���O��true�̎�.
	else if (mGameExitFlag)
	{
		// �Q�[�����[�v���I��������^�O��Ԃ�.
		return SceneTag::ExitTag;
	}

	// ����ȊO�̎��͌��݂̃V�[���^�O��Ԃ�.
	return mNowSceneTag;
}

/// <summary>
/// �`�揈��.
/// </summary>
void Title::Draw()
{
	// Background�N���X�̕`�揈��.
	mBg->Draw(ViewState::Normal);

	// Button�N���X�̕`�揈��.
	mStartBtn->Draw(ViewState::Normal);
	mExitBtn->Draw(ViewState::Normal);
}

/// <summary>
/// �V�[����ς���ۂ̓��͏����֐�.
/// </summary>
void Title::Input()
{
	// ���݂̃p�b�h�̉������{�^���̓��͏�Ԃ�ۑ�����ϐ�.
	int pad1Input;

	// �P�ڂ�JoyPad�̉������{�^���̓��͏�Ԃ��擾.
	pad1Input = GetJoypadInputState(DX_INPUT_PAD1);

	// �I���}�E�X�����摜�̃X�e�[�^�X���擾���鏈��.
	{
		// �P�ڂ�JoyPad�����L�[�{�^���������Ă�����.
		// �����̃I���}�E�X�����摜���ʂ̃X�e�[�^�X�������Ă�����.
		if (pad1Input & PAD_INPUT_LEFT
			&& this->mNowOnBtn != this->mStartBtn->GetBtnState())
		{
			// �{�^���̃X�e�[�^�X��Start�ɕύX����.
			this->mNowOnBtn = this->mStartBtn->GetBtnState();
		}
		// �P�ڂ�JoyPad���E�L�[�{�^���������Ă�����.
		// �����̃I���}�E�X�����摜���ʂ̃X�e�[�^�X�������Ă�����.
		else if (pad1Input & PAD_INPUT_RIGHT
			&& this->mNowOnBtn != this->mExitBtn->GetBtnState())
		{
			// �{�^���̃X�e�[�^�X��Exit�ɕύX����.
			this->mNowOnBtn = this->mExitBtn->GetBtnState();
		}
	}

	// ���݃I���}�E�X���Ă���{�^���摜�̃X�e�[�^�X�ɂ���ĕς�鏈��.
	{
		// �P�ڂ�JoyPad��A�{�^���������Ă�����.
		// �f�o�b�O�p�Ƃ��ăL�[�{�[�h��7�{�^������������.
		if (pad1Input & PAD_INPUT_1
			|| CheckHitKey(KEY_INPUT_7))
		{
			// �����{�^���̃X�e�[�^�X��Start��������.
			if (mNowOnBtn == mStartBtn->GetBtnState())
			{
				// �`���[�g���A���V�[����true�ɂ���.
				mChangeSceneFlag = true;
			}
			// �����{�^���̃X�e�[�^�X��Exit��������.
			else if (mNowOnBtn == mExitBtn->GetBtnState())
			{
				// �Q�[�������V�[���t���O��true�ɂ���.
				mGameExitFlag = true;
			}
		}
	}
}