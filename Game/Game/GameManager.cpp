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

	return true;
}

/// <summary>
/// �Q�[�����[�v.
/// </summary>
void GameManager::GameLoop()
{
	while (mRunningFlag)
	{
		ProcessInput();

		mReturnTag = mNowScene->Update();

		if (mReturnTag != SceneBase::mNowSceneTag)
		{
			delete mNowScene;

			CreateScene();
			continue;
		}

		DrawGame();

		UpdateGame();
	}
}

/// <summary>
/// �N���X��}�l�[�W���[�̃������������.
/// </summary>
void GameManager::terminate()
{
	delete mNowScene;
	delete mFps;

	DxLib_End();
}

void GameManager::CreateScene()
{
	if (mReturnTag == SceneBase::SceneTag::TITLE_TAG)
	{
		mNowScene = new Title();
	}
	else if (mReturnTag == SceneBase::SceneTag::PLAY_TAG)
	{
		mNowScene = new Play();
	}
	else if (mReturnTag == SceneBase::SceneTag::RESULT_TAG)
	{
		mNowScene = new Result();
	}
}

void GameManager::ProcessInput()
{
	int pad1Input;
	pad1Input = GetJoypadInputState(DX_INPUT_PAD1);

	// �E�B���h�E������ꂽ��
	// �܂���ESC�L�[�������ꂽ��
	// �܂���XBox�R���g���[���[�̃��j���[�L�[�������ꂽ��.
	if (ProcessMessage() == -1
		|| CheckHitKey(KEY_INPUT_ESCAPE)
		|| pad1Input & PAD_INPUT_10)
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