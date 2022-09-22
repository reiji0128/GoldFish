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

void FishManager::CreatePool(const int redFishSize, const int blueFishSize, const int goldFishSize)
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

void FishManager::AddFish(Fish* addFish)
{
	mFishList.push_back(addFish);
}

void FishManager::RemoveFish(Fish* addFish)
{
	mFishList.pop_back();
}

void FishManager::RemoveAll()
{
	for (int i = 0; i < mFishList.size(); i++)
	{
		delete mFishList.back();
	}
}

CollisionInfo FishManager::GetCollisionInfo(int i)
{
	mCollisionInfo.pos = mFishList[i]->GetPosition();
	mCollisionInfo.tag = mFishList[i]->GetTag();

	return mCollisionInfo;
}
