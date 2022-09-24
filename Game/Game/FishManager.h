#pragma once
#include <vector>
#include "Math.h"
#include "Tag.h"

/// <summary>
/// “–‚½‚è”»’èî•ñ
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

// ƒQƒbƒ^[ //

	/// <summary>
	/// “–‚½‚è”»’èî•ñ‚Ìæ“¾
	/// </summary>
	/// <param name="i"></param>
	/// <returns>“–‚½‚è”»’èî•ñ</returns>
	CollisionInfo GetCollisionInfo(int i);

private:
	// “–‚½‚è”»’èî•ñ
	CollisionInfo mCollisionInfo;

	std::vector<Fish*> mFishList;

	RedFish* mRedFish;
	BlueFish* mBlueFish;
	GoldFish* mGoldFish;
};
