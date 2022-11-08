#include "Play.h"
#include "DxLib.h"
#include "FishManager.h"
#include "PoiManager.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Play::Play()
	// SceneBase�N���X�̏������A�^�O��Play�Ɏw�肷��.
	:SceneBase(SceneBase::SceneTag::PlayTag)
{
	// Background�N���X�̃R���X�g���N�^�APlay�̔w�i���w�肷��.
	mBg = new Background(BgImgName[BgImgFileNum::PlayBg]);
	FishManager::InitPool();
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Play::~Play()
{
	// �������̍폜.
	delete mBg;

	// �������̏�����.
	mBg = nullptr;
}

/// <summary>
/// �X�V�֐��A�I�[�o�[���C�h�֐�.
/// </summary>
/// <param name="deltaTime">float�^�̃f���^�^�C��.</param>
/// <returns>SceneTag�^��enum�N���X��Ԃ�.</returns>
SceneBase::SceneTag Play::Updata(float deltaTime)
{
	// mChangeSceneFlag��true��������
	if (mChangeSceneFlag)
	{
		// SceneTag��ResultTag�ɂ���.
		return SceneTag::ResultTag;
	}

	// ����ȊO�̏ꍇ�͌��݂̃V�[����Ԃ�.
	return mNowSceneTag;
}

/// <summary>
/// �`��֐�.
/// </summary>
void Play::Draw()
{
	// Background�N���X�̕`�揈��.
	mBg->Draw();

	// FishManager�̕`�揈��
	FishManager::Draw();

	PoiManager::Draw();
	
	//UI�N���X�̕`��
	ui->Draw();
}

/// <summary>
/// �V�[����ς���ۂ̓��͏����֐�.
/// </summary>
void Play::Input()
{
	// ������Play���I�������ۂ�Flag��State�����L������.@@@
	// �܂��̓f�o�b�O�p�Ƃ��ăL�[�{�[�h��9�{�^������������.
	if (CheckHitKey(KEY_INPUT_9))
	{
		// mChangeSceneFlag��true�ɂ���
		mChangeSceneFlag = true;
	}
}