#include "Result.h"
#include "DxLib.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Result::Result()
	:SceneBase(SceneBase::SceneTag::RESULT_TAG)
{
	mBg = new Background(BgImgName[BgImgFileNum::RESULT_IMG]);
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Result::~Result()
{
}

/// <summary>
/// �X�V�֐�.
/// </summary>
/// <param name="deltaTime">float�^�̃f���^�^�C���̈���.</param>
/// <returns>SceneTag�^��enum�N���X��Ԃ�.</returns>
SceneBase::SceneTag Result::Update()
{
	// �^�C�g���V�[���ւ̈ڍs����.
	if (mChangeSceneFlag)
	{
		return SceneTag::TITLE_TAG;
	}

	// ����ȊO�͂��̃V�[����Ԃ�.
	return mNowSceneTag;
}

/// <summary>
/// �`��֐�.
/// </summary>
void Result::Draw()
{
	mBg->Draw();
}

void Result::Input()
{
	int pad1Input;
	pad1Input = GetJoypadInputState(DX_INPUT_PAD1);

	if (pad1Input & PAD_INPUT_1)
	{
		// �V�[����ς���t���O��true�ɂ���.
		mChangeSceneFlag = true;
	}
}