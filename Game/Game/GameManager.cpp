#include "GameManager.h"
#include "DxLib.h"

#include "Title.h"
#include "Tutorial.h"
#include "Play.h"
#include "Result.h"
#include "Exit.h"

#include "FishManager.h"
#include "PoiManager.h"
//-----------------必要な時にヘッダーファイルをインクルードしてください.-------------------//

/// <summary>
/// コンストラクタ.
/// </summary>
GameManager::GameManager()
	:MColorBitNum(16)                         // ウィンドウのカラービットの数.
	,mRunningFlag(true)                       // ゲームループを回すかどうかを保存するフラグ、trueならループが回りfalseならループから抜ける.
	,mNowSceneClass(nullptr)                  // 現在のシーンクラスを保存する変数.
	,mReturnTag(SceneBase::mNowSceneTag)      // 次のシーンのタグを保存する変数.
	,mFps(nullptr)                            // fpsクラスを保存する変数.
{
}

/// <summary>
/// 初期化処理.
/// </summary>
/// <returns>もし成功すればtrueが、失敗すればfalseが返ってくる.</returns>
bool GameManager::Initialize()
{
	// ウィンドウのサイズとカラービットを指定する.
	SetGraphMode(MWidth, MHeight, MColorBitNum);

	// フルスクリーンを避けるため、ウィンドウモードにする.
	ChangeWindowMode(TRUE);

	// Dxlibがエラーを起こしていた時はreturnでfalseを返す.
	if (DxLib_Init() == -1)
	{
		return false;
	}

	// fpsを計測するために
	mFps = new FPS();

	// 1つしか実態を持たないクラスの生成.
	// 例）UIManager::CreateInstance();
	//     ActorManager::CreateInstance();
	FishManager::CreateInstance();
	FishManager::CreatePool(1, 1, 1, 1);

	PoiManager::CreateInstance();

	// 問題がなければtrueを返す.
	return true;
}

/// <summary>
/// ゲームループ.
/// </summary>
void GameManager::GameLoop()
{
	// ループを回すかどうかのフラグがtrueだった時
	while (mRunningFlag)
	{
		// ループを抜ける際に使用する入力処理関数.
		ProcessInput();

		// 現在のシーンを次のシーンを保存する変数に保存する.
		mReturnTag = mNowSceneClass->Updata();

		// 次のシーンが今のシーンと違ったとき.
		if (mReturnTag != SceneBase::mNowSceneTag)
		{
			// 今のシーンを削除する.
			delete mNowSceneClass;

			// 新しくシーンを生成する.
			CreateScene();

			// 以下の処理を飛ばしてwhileからループしなおす.
			continue;
		}

		// 描画処理関数.
		DrawGame();

		// 更新処理関数.
		UpdateGame();
	}
}

/// <summary>
/// クラスやマネージャーのメモリ解放処理.
/// </summary>
void GameManager::terminate()
{
	// 1つしか実態を持たないクラスの削除.
	// 例）UIManager::DeleteInstance();
	//     ActorManager::DeleteInstance();
	FishManager::DeleteInstance();

	PoiManager::DeleteInstance();

	// その他単体のクラスを持つ変数の削除.
	delete mNowSceneClass;
	delete mFps;

	// Dxlibの終了処理.
	DxLib_End();
}

/// <summary>
/// mReturnTagを使用した新しいシーンを生成する関数.
/// </summary>
void GameManager::CreateScene()
{
	// 次のタグがタイトルシーンのタグだった時.
	if (mReturnTag == SceneBase::SceneTag::TitleTag)
	{
		// タイトルクラスを生成する.
		mNowSceneClass = new Title();
	}
	// 次のタグがチュートリアルシーンのタグだった時.
	else if (mReturnTag == SceneBase::SceneTag::TutorialTag)
	{
		// チュートリアルクラスを生成する.
		mNowSceneClass = new Tutorial();
	}
	// 次のタグがプレイシーンのタグだった時.
	else if (mReturnTag == SceneBase::SceneTag::PlayTag)
	{
		// プレイクラスを生成する.
		mNowSceneClass = new Play();
	}
	// 次のタグがリザルトシーンのタグだった時.
	else if (mReturnTag == SceneBase::SceneTag::ResultTag)
	{
		// リザルトクラスを生成する.
		mNowSceneClass = new Result();
	}
	else if (mReturnTag == SceneBase::SceneTag::ExitTag)
	{
		mNowSceneClass = new Exit();
	}
	else
	{
		// 前のシーンタグを現在のシーンタグへ代入する.@@@
		mNowSceneClass->mNowSceneTag = mReturnTag;
	}
}

/// <summary>
/// ループを抜ける際に使用する入力処理関数.
/// </summary>
void GameManager::ProcessInput()
{
	// ウィンドウが閉じられた時
	// またはESCキーが押された時
	// または現在のシーンタグがExitTagだった時.
	if (ProcessMessage() == -1
		|| CheckHitKey(KEY_INPUT_ESCAPE)
		|| mNowSceneClass->mNowSceneTag == SceneBase::SceneTag::ExitTag)
	{
		// ゲームループを抜けるためにフラグをfalseにする.
		mRunningFlag = false;
	}
	else
	{
		// 現在のシーン別の入力処理.
		mNowSceneClass->Input();
	}
}

/// <summary>
/// 更新処理.
/// </summary>
void GameManager::UpdateGame()
{
	// deltaTimeをfpsクラスから受け取る.
	float deltaTime = mFps->GetDeltaTime();

	//----------------それぞれの更新処理---------------------

	// FishManagerの更新処理
	FishManager::Update(deltaTime);
	//-------------------------------------

	PoiManager::Update(deltaTime);

	// fpsクラスを更新する.
	mFps->Update();

}

/// <summary>
/// 描画処理.
/// </summary>
void GameManager::DrawGame()
{
	// 画面を一度消去する.
	ClearDrawScreen();

	//------------------それぞれの描画処理---------------------

	// 現在のシーンを描画する.
	mNowSceneClass->Draw();

	//---------------------------------------

	// 裏スクリーンに描画したものを表に表示する.
	ScreenFlip();
}