#include "FishManager.h"
#include "BaseObject.h"
#include "Fish.h"
#include "RedFish.h"
#include "BlueFish.h"
#include "GoldFish.h"
#include "BlackFish.h"

// FishManager実体へのポインタ定義
FishManager* FishManager::mInstance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
FishManager::FishManager()
{
	mInstance = nullptr;
}

/// <summary>
/// デストラクタ
/// </summary>
FishManager::~FishManager()
{
	// プールの全要素を解放&削除
	RemoveAll();
}

/// <summary>
/// マネージャーのインスタンス作成
/// </summary>
void FishManager::CreateInstance()
{
	// nullptrなら生成
	if (!mInstance)
	{
		mInstance = new FishManager;
	}
}

/// <summary>
/// マネージャーの削除
/// </summary>
void FishManager::DeleteInstance()
{
	// nullptrでなければ解放
	if (mInstance)
	{
		delete mInstance;
		mInstance = nullptr;
	}
}

/// <summary>
/// マネージャーの更新処理
/// </summary>
/// <param name="deltaTime">1フレームの経過時間</param>
void FishManager::Update(float deltaTime)
{
	for (auto pool : mInstance->mFishPool)
	{
		pool->Update(deltaTime);
	}
}

/// <summary>
/// 描画処理
/// </summary>
void FishManager::Draw()
{
	for (auto pool : mInstance->mFishPool)
	{
		pool->Draw();
	}
}

/// <summary>
/// 金魚を格納するオブジェクトプールの作成
/// </summary>
/// <param name="redFishSize">生成する赤色の金魚の数</param>
/// <param name="blueFishSize">生成する青色の金魚の数</param>
/// <param name="goldFishSize">生成する金色の金魚の数</param>
/// <param name="blackFishSize">生成する黒色の金魚の数</param>
void FishManager::CreatePool(const int redFishSize, const int blueFishSize, const int goldFishSize, const int blackFishSize)
{
	// 赤色の金魚の追加
	for (int i = 0; i < redFishSize; i++)
	{
		mInstance->mRedFish = new RedFish(Tag::RedFish);
		AddFish(mInstance->mRedFish);
	}

	// 青色の金魚の追加
	for (int i = 0; i < blueFishSize; i++)
	{
		mInstance->mBlueFish = new BlueFish(Tag::BlueFish);
		AddFish(mInstance->mBlueFish);
	}

	// 金色の金魚の追加
	for (int i = 0; i < goldFishSize; i++)
	{
		mInstance->mGoldFish = new GoldFish(Tag::GoldFish);
		AddFish(mInstance->mGoldFish);
	}

	// 黒色の金魚の追加
	for (int i = 0; i < blackFishSize; i++)
	{
		mInstance->mBlackFish = new BlackFish(Tag::BlackFish);
		AddFish(mInstance->mBlackFish);
	}
}

/// <summary>
/// オブジェクトプールに金魚を追加
/// </summary>
/// <param name="addFish">追加する金魚</param>
void FishManager::AddFish(Fish* addFish)
{
	mInstance->mFishPool.push_back(addFish);
}

/// <summary>
/// オブジェクトプールの金魚の削除
/// </summary>
/// <param name="removeFish">削除する金魚</param>
void FishManager::RemoveFish(Fish* addFish)
{
	mInstance->mFishPool.pop_back();
}

/// <summary>
/// オブジェクトプールのすべての要素の削除
/// </summary>
void FishManager::RemoveAll()
{
	// プールの最後の要素をdeleteした後に削除
	while (!mInstance->mFishPool.empty())
	{
		delete mInstance->mFishPool.back();
		mInstance->mFishPool.pop_back();
	}
}

/// <summary>
/// 当たり判定情報の取得
/// </summary>
/// <param name="i">取得する要素番号</param>
/// <returns>当たり判定情報</returns>
CollisionInfo FishManager::GetCollisionInfo(int i)
{
	mInstance->mCollisionInfo.pos = mInstance->mFishPool[i]->GetPosition();
	mInstance->mCollisionInfo.tag = mInstance->mFishPool[i]->GetTag();

	return mInstance->mCollisionInfo;
}
