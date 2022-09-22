#pragma once
#include <vector>
#include "Math.h"
#include "Tag.h"

/// <summary>
/// �����蔻����
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

// �Q�b�^�[ //

	/// <summary>
	/// �����蔻����̎擾
	/// </summary>
	/// <param name="i"></param>
	/// <returns>�����蔻����</returns>
	CollisionInfo GetCollisionInfo(int i);

private:
	// �����蔻����
	CollisionInfo mCollisionInfo;

	std::vector<Fish*> mFishList;

	RedFish* mRedFish;
	BlueFish* mBlueFish;
	GoldFish* mGoldFish;
};
