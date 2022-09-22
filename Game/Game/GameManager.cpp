#include "GameManager.h"
#include "DxLib.h"

#include "Title.h"
#include "Play.h"
#include "Result.h"

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

	// ���̑��P�̂̃N���X�����ϐ��̍폜.
	delete mNowScene;
	delete mFps;

	// Dxlib�̏I������.
	DxLib_End();
}

/// <summary>
/// mReturnTag���g�p�����V�����V�[���𐶐�����֐�.
/// </summary>
void GameManager::CreateScene()
{
	// ���̃^�O���^�C�g���V�[���^�O��������.
	if (mReturnTag == SceneBase::SceneTag::TITLE_TAG)
	{
		// �^�C�g���N���X�𐶐�����.
		mNowScene = new Title();
	}
	// ���̃^�O���v���C�V�[���^�O��������.
	else if (mReturnTag == SceneBase::SceneTag::PLAY_TAG)
	{
		// �v���C�N���X�𐶐�����.
		mNowScene = new Play();
	}
	// ���̃^�O�����U���g�V�[���^�O��������.
	else if (mReturnTag == SceneBase::SceneTag::RESULT_TAG)
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
		mRunningFlag = false;
	}

	// ���݂̓��͏���.
	mNowScene->Input();
}

/// <summary>
/// �X�V����.
/// </summary>
void GameManager::UpdateGame()
{
	float deltaTime = mFps->GetDeltaTime();

	//-------------------------------------

	//-------------------------------------

	mFps->Update();
}

/// <summary>
/// �`�揈��.
/// </summary>
void GameManager::DrawGame()
{
	ClearDrawScreen();

	//---------------------------------------

	mNowScene->Draw();

	//---------------------------------------


	ScreenFlip();
}