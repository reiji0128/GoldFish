#include "GameManager.h"
#include "DxLib.h"

#include "Title.h"
#include "Play.h"
#include "Result.h"

/// <summary>
/// コンストラクタ.
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

	// 1つしか実態を持たないクラスの生成.
	// 例）UIManager::CreateInstance();
	//     ActorManager::CreateInstance();

	return true;
}

/// <summary>
/// ゲームループ.
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
/// クラスやマネージャーのメモリ解放処理.
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

	// ウィンドウが閉じられた時
	// またはESCキーが押された時
	// またはXBoxコントローラーのメニューキーが押された時.
	if (ProcessMessage() == -1
		|| CheckHitKey(KEY_INPUT_ESCAPE)
		|| pad1Input & PAD_INPUT_10)
	{
		mRunningFlag = false;
	}

	// 現在の入力処理.
	mNowScene->Input();
}

/// <summary>
/// 更新処理.
/// </summary>
void GameManager::UpdateGame()
{
	float deltaTime = mFps->GetDeltaTime();

	//-------------------------------------

	//-------------------------------------

	mFps->Update();
}

/// <summary>
/// 描画処理.
/// </summary>
void GameManager::DrawGame()
{
	ClearDrawScreen();

	//---------------------------------------

	mNowScene->Draw();

	//---------------------------------------


	ScreenFlip();
}