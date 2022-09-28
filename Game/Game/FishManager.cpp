#include "FishManager.h"
#include "BaseObject.h"
#include "Fish.h"
#include "RedFish.h"
#include "BlueFish.h"
#include "GoldFish.h"
#include "BlackFish.h"

// FishManager実体へのポインタ定義
FishManager* FishManager::mInstance = nullptr;

FishManager::FishManager()
{
	mInstance = nullptr;
}

FishManager::~FishManager()
{
	RemoveAll();
}

void FishManager::CreateInstance()
{
	if (!mInstance)
	{
		mInstance = new FishManager;
	}
}

void FishManager::DeleteInstance()
{
	if (mInstance)
	{
		delete mInstance;
		mInstance = nullptr;
	}
}

void FishManager::Update(float deltaTime)
{
	for (auto pool : mInstance->mFishPool)
	{
		pool->Update(deltaTime);
	}
}

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
	for (int i = 0; i < redFishSize; i++)
	{
		mInstance->mRedFish = new RedFish(Tag::RedFish);
		AddFish(mInstance->mRedFish);
	}
	for (int i = 0; i < blueFishSize; i++)
	{
		mInstance->mBlueFish = new BlueFish(Tag::BlueFish);
		AddFish(mInstance->mBlueFish);
	}
	for (int i = 0; i < goldFishSize; i++)
	{
		mInstance->mGoldFish = new GoldFish(Tag::GoldFish);
		AddFish(mInstance->mGoldFish);
	}
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
	for (int i = 0; i < mInstance->mFishPool.size(); i++)
	{
		delete mInstance->mFishPool.back();
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
