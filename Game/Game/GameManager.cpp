#include "GameManager.h"
#include "DxLib.h"

#include "Title.h"
#include "Play.h"
#include "Result.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
GameManager::GameManager()
	:MWidth(1920)
	,MHeight(1080)
	,MColorBitNum(16)
	,MZbitNum(24)
	,mRunningFlag(true)
	,mNowScene(nullptr)
	,mReturnTag(SceneBase::mNowSceneTag)
	,mFps(nullptr)
{
}

bool GameManager::Initialize()
{
	SetGraphMode(MWidth, MHeight, MColorBitNum);
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return false;
	}

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