#include "Result.h"
#include "DxLib.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Result::Result()
	// SceneBase�N���X�̏������A�V�[���^�O��ResultTag���w�肷��.
	:SceneBase(SceneBase::SceneTag::ResultTag)
{
	// Background�N���X�̃R���X�g���N�^�AResult�̔w�i���w�肷��.
	mBg = new Background(BgImgName[BgImgFileNum::ResultBg]);
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
/// <returns>SceneTag�^��enum�N���X��Ԃ�.</returns>
SceneBase::SceneTag Result::Update()
{
	// mChangeSceneFlag��true�̎�.
	if (mChangeSceneFlag)
	{
		// ResultTag��Ԃ�.
		return SceneTag::TitleTag;
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
	mBg->Draw();
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

	// �P�ڂ�JoyPad��A�{�^���������Ă�����.
	// �f�o�b�N�p�Ƃ��ăL�[�{�[�h��0�{�^������������.
	if (pad1Input & PAD_INPUT_1
		|| CheckHitKey(KEY_INPUT_0))
	{
		// �V�[����ς���t���O��true�ɂ���.
		mChangeSceneFlag = true;
	}
}