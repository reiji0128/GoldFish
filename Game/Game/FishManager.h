#pragma once
#include <vector>
#include "Math.h"
#include "Tag.h"

/// <summary>
/// 当たり判定情報
/// </summary>
struct CollisionInfo
{
	Vector2 pos;
	Tag tag;
};

class Fish;
class RedFish;
class BlueFish;
class GoldFish;

class FishManager final
{
public:
	FishManager();
	~FishManager();

	void CreatePool(const int redFishSize,
					const int blueFishSize,
					const int goldFishSize);
	void AddFish(Fish* addFish);
	void RemoveFish(Fish* removeFish);
	void RemoveAll();

// ゲッター //

	/// <summary>
	/// 当たり判定情報の取得
	/// </summary>
	/// <param name="i"></param>
	/// <returns>当たり判定情報</returns>
	CollisionInfo GetCollisionInfo(int i);

private:
	// 当たり判定情報
	CollisionInfo mCollisionInfo;

	std::vector<Fish*> mFishList;

	RedFish* mRedFish;
	BlueFish* mBlueFish;
	GoldFish* mGoldFish;
};
