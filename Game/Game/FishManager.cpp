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
/// �������i�[����I�u�W�F�N�g�v�[���̍쐬
/// </summary>
/// <param name="redFishSize">��������ԐF�̋����̐�</param>
/// <param name="blueFishSize">��������F�̋����̐�</param>
/// <param name="goldFishSize">����������F�̋����̐�</param>
/// <param name="blackFishSize">�������鍕�F�̋����̐�</param>
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
/// �I�u�W�F�N�g�v�[���ɋ�����ǉ�
/// </summary>
/// <param name="addFish">�ǉ��������</param>
void FishManager::AddFish(Fish* addFish)
{
	mFishPool.push_back(addFish);
}

/// <summary>
/// �I�u�W�F�N�g�v�[���̋����̍폜
/// </summary>
/// <param name="removeFish">�폜�������</param>
void FishManager::RemoveFish(Fish* addFish)
{
	mFishPool.pop_back();
}

/// <summary>
/// �I�u�W�F�N�g�v�[���̂��ׂĂ̗v�f�̍폜
/// </summary>
void FishManager::RemoveAll()
{
	for (int i = 0; i < mFishPool.size(); i++)
	{
		delete mFishPool.back();
	}
}

/// <summary>
/// �����蔻����̎擾
/// </summary>
/// <param name="i">�擾����v�f�ԍ�</param>
/// <returns>�����蔻����</returns>
CollisionInfo FishManager::GetCollisionInfo(int i)
{
	mCollisionInfo.pos = mFishPool[i]->GetPosition();
	mCollisionInfo.tag = mFishPool[i]->GetTag();

	return mCollisionInfo;
}
