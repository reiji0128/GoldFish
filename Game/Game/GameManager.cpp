#include "GameManager.h"
#include "DxLib.h"

#include "Title.h"
#include "Play.h"
#include "Result.h"

#include "FishManager.h"
//-----------------必要な時にヘッダーファイルをインクルードしてください.-------------------//

/// <summary>
/// コンストラクタ.
/// </summary>
GameManager::GameManager()
	:MWidth(1920)                             // ウィンドウのx軸のサイズ.
	,MHeight(1080)                            // ウィンドウのy軸のサイズ.
	,MColorBitNum(16)                         // ウィンドウのカラービットの数.
	,mRunningFlag(true)                       // ゲームループを回すかどうかを保存するフラグ、trueならループが回りfalseならループから抜ける.
	,mNowScene(nullptr)                       // 現在のシーンを保存する変数.
	,mReturnTag(SceneBase::mNowSceneTag)      // 次のシーンのタグを保存する変数.
	,mFps(nullptr)                            // fpsクラスを保存する変数.
	,mPoi1(nullptr)                           // プレイヤー1を保存する変数.
	,mPoi2(nullptr)                           // プレイヤー2を保存する変数.
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

	// プレイヤーの生成
	mPoi1 = new Poi(1);
	mPoi2 = new Poi(2);

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
		mReturnTag = mNowScene->Update();

		// 次のシーンが今のシーンと違ったとき.
		if (mReturnTag != SceneBase::mNowSceneTag)
		{
			// 今のシーンを削除する.
			delete mNowScene;

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

	// その他単体のクラスを持つ変数の削除.
	delete mNowScene;
	delete mFps;

	delete mPoi1;
	delete mPoi2;

	// Dxlibの終了処理.
	DxLib_End();
}

/// <summary>
/// mReturnTagを使用した新しいシーンを生成する関数.
/// </summary>
void GameManager::CreateScene()
{
	// 次のタグがタイトルシーンタグだった時.
	if (mReturnTag == SceneBase::SceneTag::TitleTag)
	{
		// タイトルクラスを生成する.
		mNowScene = new Title();
	}
	// 次のタグがプレイシーンタグだった時.
	else if (mReturnTag == SceneBase::SceneTag::PlayTag)
	{
		// プレイクラスを生成する.
		mNowScene = new Play();
	}
	// 次のタグがリザルトシーンタグだった時.
	else if (mReturnTag == SceneBase::SceneTag::ResultTag)
	{
		// リザルトクラスを生成する.
		mNowScene = new Result();
	}
}

/// <summary>
/// ループを抜ける際に使用する入力処理関数.
/// </summary>
void GameManager::ProcessInput()
{
	// 一つ目のXBoxコントローラーが押されたボタンの番号を保存する変数.
	int pad1Input;

	// 一つ目のXBoxコントローラーの押されたボタンの番号を保存する.
	pad1Input = GetJoypadInputState(DX_INPUT_PAD1);

	// ウィンドウが閉じられた時
	// またはESCキーが押された時
	// またはXBoxコントローラーのメニューキーが押された時.
	if (ProcessMessage() == -1
		|| CheckHitKey(KEY_INPUT_ESCAPE)
		|| pad1Input & PAD_INPUT_11)
	{
		// ゲームループを抜けるためにフラグをfalseにする.
		mRunningFlag = false;
	}

	// 現在のシーン別の入力処理.
	mNowScene->Input();
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

	// fpsクラスを更新する.
	mFps->Update();

	//-------------------------------------
	// プレイヤーの更新.
	mPoi1->Update(deltaTime);
	mPoi2->Update(deltaTime);
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
	mNowScene->Draw();

	//---------------------------------------

	// プレイヤーの描画.
	mPoi1->Draw();
	mPoi2->Draw();

	// 裏スクリーンに描画したものを表に表示する.
	ScreenFlip();
}