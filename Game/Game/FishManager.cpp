#include "FishManager.h"
#include "BaseObject.h"
#include "Fish.h"
#include "RedFish.h"
#include "BlueFish.h"
#include "GoldFish.h"

FishManager::FishManager()
{
}

FishManager::~FishManager()
{
	RemoveAll();
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
	for (int i = 0; redFishSize; i++)
	{
		mRedFish = new RedFish(Tag::RedFish);
		AddFish(mRedFish);
	}
	for (int i = 0; blueFishSize; i++)
	{
		mBlueFish = new BlueFish(Tag::BlueFish);
		AddFish(mBlueFish);
	}
	for (int i = 0; goldFishSize; i++)
	{
		mGoldFish = new GoldFish(Tag::GoldFish);
		AddFish(mGoldFish);
	}
}

/// <summary>
/// オブジェクトプールに金魚を追加
/// </summary>
/// <param name="addFish">追加する金魚</param>
void FishManager::AddFish(Fish* addFish)
{
	mFishPool.push_back(addFish);
}

/// <summary>
/// オブジェクトプールの金魚の削除
/// </summary>
/// <param name="removeFish">削除する金魚</param>
void FishManager::RemoveFish(Fish* addFish)
{
	mFishPool.pop_back();
}

/// <summary>
/// オブジェクトプールのすべての要素の削除
/// </summary>
void FishManager::RemoveAll()
{
	for (int i = 0; i < mFishPool.size(); i++)
	{
		delete mFishPool.back();
	}
}

/// <summary>
/// 当たり判定情報の取得
/// </summary>
/// <param name="i">取得する要素番号</param>
/// <returns>当たり判定情報</returns>
CollisionInfo FishManager::GetCollisionInfo(int i)
{
	mCollisionInfo.pos = mFishPool[i]->GetPosition();
	mCollisionInfo.tag = mFishPool[i]->GetTag();

	return mCollisionInfo;
}
