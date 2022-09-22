#include "Play.h"
#include "DxLib.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Play::Play()
	:SceneBase(SceneBase::SceneTag::PLAY_TAG)
{
	mBg = new Background(BgImgName[BgImgFileNum::PLAY_IMG]);
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Play::~Play()
{
}

/// <summary>
/// �X�V�֐�.
/// </summary>
/// <param name="deltaTime">float�^�̃f���^�^�C���̈���.</param>
/// <returns>SCENE_TAG�^��enum�N���X��Ԃ�.</returns>
SceneBase::SceneTag Play::Update()
{
	//gameManager->Update(deltaTime);

	// ����̏����Ń��U���g�V�[�����ڍs���鏈��
	if (mChangeSceneFlag)
	{
		return SceneTag::RESULT_TAG;
	}

	// ����ȊO�̏ꍇ�͂��̃V�[����Ԃ�.
	return mNowSceneTag;
}

/// <summary>
/// �`��֐�.
/// </summary>
void Play::Draw()
{
	mBg->Draw();
}

void Play::Input()
{
	// �����ɃV�[����ς��������mChangeSceneFlag��ς���.
	if (CheckHitKey(KEY_INPUT_9))
	{
		mChangeSceneFlag = true;
	}
	else
	{
		mChangeSceneFlag = false;
	}
}