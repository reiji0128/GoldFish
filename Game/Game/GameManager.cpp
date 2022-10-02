#include "GameManager.h"
#include "DxLib.h"

#include "Title.h"
#include "Play.h"
#include "Result.h"

#include "FishManager.h"
//-----------------�K�v�Ȏ��Ƀw�b�_�[�t�@�C�����C���N���[�h���Ă�������.-------------------//

/// <summary>
/// �R���X�g���N�^.
/// </summary>
GameManager::GameManager()
	:MWidth(1920)                             // �E�B���h�E��x���̃T�C�Y.
	,MHeight(1080)                            // �E�B���h�E��y���̃T�C�Y.
	,MColorBitNum(16)                         // �E�B���h�E�̃J���[�r�b�g�̐�.
	,mRunningFlag(true)                       // �Q�[�����[�v���񂷂��ǂ�����ۑ�����t���O�Atrue�Ȃ烋�[�v�����false�Ȃ烋�[�v���甲����.
	,mNowScene(nullptr)                       // ���݂̃V�[����ۑ�����ϐ�.
	,mReturnTag(SceneBase::mNowSceneTag)      // ���̃V�[���̃^�O��ۑ�����ϐ�.
	,mFps(nullptr)                            // fps�N���X��ۑ�����ϐ�.
	,mPoi1(nullptr)                           // �v���C���[1��ۑ�����ϐ�.
	,mPoi2(nullptr)                           // �v���C���[2��ۑ�����ϐ�.
{
}

/// <summary>
/// ����������.
/// </summary>
/// <returns>�������������true���A���s�����false���Ԃ��Ă���.</returns>
bool GameManager::Initialize()
{
	// �E�B���h�E�̃T�C�Y�ƃJ���[�r�b�g���w�肷��.
	SetGraphMode(MWidth, MHeight, MColorBitNum);

	// �t���X�N���[��������邽�߁A�E�B���h�E���[�h�ɂ���.
	ChangeWindowMode(TRUE);

	// Dxlib���G���[���N�����Ă�������return��false��Ԃ�.
	if (DxLib_Init() == -1)
	{
		return false;
	}

	// fps���v�����邽�߂�
	mFps = new FPS();

	// 1�������Ԃ������Ȃ��N���X�̐���.
	// ��jUIManager::CreateInstance();
	//     ActorManager::CreateInstance();
	FishManager::CreateInstance();

	// �v���C���[�̐���
	mPoi1 = new Poi(1);
	mPoi2 = new Poi(2);

	// ��肪�Ȃ����true��Ԃ�.
	return true;
}

/// <summary>
/// �Q�[�����[�v.
/// </summary>
void GameManager::GameLoop()
{
	// ���[�v���񂷂��ǂ����̃t���O��true��������
	while (mRunningFlag)
	{
		// ���[�v�𔲂���ۂɎg�p������͏����֐�.
		ProcessInput();

		// ���݂̃V�[�������̃V�[����ۑ�����ϐ��ɕۑ�����.
		mReturnTag = mNowScene->Update();

		// ���̃V�[�������̃V�[���ƈ�����Ƃ�.
		if (mReturnTag != SceneBase::mNowSceneTag)
		{
			// ���̃V�[�����폜����.
			delete mNowScene;

			// �V�����V�[���𐶐�����.
			CreateScene();

			// �ȉ��̏������΂���while���烋�[�v���Ȃ���.
			continue;
		}

		// �`�揈���֐�.
		DrawGame();

		// �X�V�����֐�.
		UpdateGame();
	}
}

/// <summary>
/// �N���X��}�l�[�W���[�̃������������.
/// </summary>
void GameManager::terminate()
{
	// 1�������Ԃ������Ȃ��N���X�̍폜.
	// ��jUIManager::DeleteInstance();
	//     ActorManager::DeleteInstance();
	FishManager::DeleteInstance();

	// ���̑��P�̂̃N���X�����ϐ��̍폜.
	delete mNowScene;
	delete mFps;

	delete mPoi1;
	delete mPoi2;

	// Dxlib�̏I������.
	DxLib_End();
}

/// <summary>
/// mReturnTag���g�p�����V�����V�[���𐶐�����֐�.
/// </summary>
void GameManager::CreateScene()
{
	// ���̃^�O���^�C�g���V�[���^�O��������.
	if (mReturnTag == SceneBase::SceneTag::TitleTag)
	{
		// �^�C�g���N���X�𐶐�����.
		mNowScene = new Title();
	}
	// ���̃^�O���v���C�V�[���^�O��������.
	else if (mReturnTag == SceneBase::SceneTag::PlayTag)
	{
		// �v���C�N���X�𐶐�����.
		mNowScene = new Play();
	}
	// ���̃^�O�����U���g�V�[���^�O��������.
	else if (mReturnTag == SceneBase::SceneTag::ResultTag)
	{
		// ���U���g�N���X�𐶐�����.
		mNowScene = new Result();
	}
}

/// <summary>
/// ���[�v�𔲂���ۂɎg�p������͏����֐�.
/// </summary>
void GameManager::ProcessInput()
{
	// ��ڂ�XBox�R���g���[���[�������ꂽ�{�^���̔ԍ���ۑ�����ϐ�.
	int pad1Input;

	// ��ڂ�XBox�R���g���[���[�̉����ꂽ�{�^���̔ԍ���ۑ�����.
	pad1Input = GetJoypadInputState(DX_INPUT_PAD1);

	// �E�B���h�E������ꂽ��
	// �܂���ESC�L�[�������ꂽ��
	// �܂���XBox�R���g���[���[�̃��j���[�L�[�������ꂽ��.
	if (ProcessMessage() == -1
		|| CheckHitKey(KEY_INPUT_ESCAPE)
		|| pad1Input & PAD_INPUT_11)
	{
		// �Q�[�����[�v�𔲂��邽�߂Ƀt���O��false�ɂ���.
		mRunningFlag = false;
	}

	// ���݂̃V�[���ʂ̓��͏���.
	mNowScene->Input();
}

/// <summary>
/// �X�V����.
/// </summary>
void GameManager::UpdateGame()
{
	// deltaTime��fps�N���X����󂯎��.
	float deltaTime = mFps->GetDeltaTime();

	//----------------���ꂼ��̍X�V����---------------------

	// FishManager�̍X�V����
	FishManager::Update(deltaTime);
	//-------------------------------------

	// fps�N���X���X�V����.
	mFps->Update();

	//-------------------------------------
	// �v���C���[�̍X�V.
	mPoi1->Update(deltaTime);
	mPoi2->Update(deltaTime);
}

/// <summary>
/// �`�揈��.
/// </summary>
void GameManager::DrawGame()
{
	// ��ʂ���x��������.
	ClearDrawScreen();

	//------------------���ꂼ��̕`�揈��---------------------

	// ���݂̃V�[����`�悷��.
	mNowScene->Draw();

	//---------------------------------------

	// �v���C���[�̕`��.
	mPoi1->Draw();
	mPoi2->Draw();

	// ���X�N���[���ɕ`�悵�����̂�\�ɕ\������.
	ScreenFlip();
}