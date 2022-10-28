#include "Result.h"
#include "DxLib.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Result::Result()
	// SceneBase�N���X�̏������A�V�[���^�O��ResultTag���w�肷��.
	:SceneBase(SceneBase::SceneTag::ResultTag)
	// �^�C�g���Ɉڍs����Button�N���X�̕ϐ��̏�����.
	,mTitleBtn(nullptr)
	// �Q�[�������Button�N���X�̕ϐ��̏�����.
	,mExitBtn(nullptr)
	// ���݃I���}�E�X��Ԃɂ���{�^���̃X�e�[�^�X�̏�����.
	,mNowOnBtn(BtnState::None)
{
	// Background�N���X�̃R���X�g���N�^�AResult�̔w�i���w�肷��.
	mBg = new Background(BgImgName[BgImgFileNum::ResultBg]);

	// Button�N���X�̃R���X�g���N�^.
	mTitleBtn = new Button(ButtonImgName[ButtonImgFileNum::TitleBtn], BtnState::Title);
	mExitBtn = new Button(ButtonImgName[ButtonImgFileNum::ExitBtn], BtnState::Exit);

	// Button�N���X�̍��W�ݒ�.@@@(��)
	mTitleBtn->SetPosition(Vector2(100, 100));
	mExitBtn->SetPosition(Vector2(200, 200));

	// ���݃I���}�E�X��Ԃɂ���{�^���̃X�e�[�^�X����.
	mNowOnBtn = mTitleBtn->GetBtnState();
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Result::~Result()
{
	// �������̍폜.
	delete mBg;
	delete mTitleBtn;
	delete mExitBtn;
}

/// <summary>
/// �X�V�֐�.
/// </summary>
/// <returns>SceneTag�^��enum�N���X��Ԃ�.</returns>
SceneBase::SceneTag Result::Updata()
{
	// mChangeSceneFlag��true�̎�.
	if (mChangeSceneFlag)
	{
		// ���U���g���[��̃^�O��Ԃ�.
		return SceneTag::TitleTag;
	}
	// �Q�[�����I��点��t���O��true�̎�.
	else if (mGameExitFlag)
	{
		// �Q�[�����[�v���I��������^�O��Ԃ�.
		return SceneTag::ExitTag;
	}

	// ����ȊO�͂��̃V�[����Ԃ�.
	return mNowSceneTag;
}

/// <summary>
/// �`��֐�.
/// </summary>
void Result::Draw()
{
	// Background�N���X�̕`��֐�.
	mBg->Draw(ViewState::Normal);

	// Button�N���X�̕`��֐�.
	mTitleBtn->Draw(ViewState::Normal);
	mExitBtn->Draw(ViewState::Normal);
}

/// <summary>
/// �V�[����ς���ۂ̓��͏����֐�.
/// </summary>
void Result::Input()
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
			&& this->mNowOnBtn != this->mTitleBtn->GetBtnState())
		{
			// �{�^���̃X�e�[�^�X��Start�ɕύX����.
			this->mNowOnBtn = this->mTitleBtn->GetBtnState();
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
		// �f�o�b�N�p�Ƃ��ăL�[�{�[�h��0�{�^������������.
		if (pad1Input & PAD_INPUT_1
			|| CheckHitKey(KEY_INPUT_0))
		{
			// �����{�^���̃X�e�[�^�X��Title��������.
			if (mNowOnBtn == this->mTitleBtn->GetBtnState())
			{
				// �V�[����ς���t���O��true�ɂ���.
				mChangeSceneFlag = true;
			}
			// �����{�^���̃X�e�[�^�X��Exit��������.
			else if (mNowOnBtn == this->mExitBtn->GetBtnState())
			{
				// �Q�[�������V�[���t���O��true�ɂ���.
				mGameExitFlag = true;
			}
		}
	}

}