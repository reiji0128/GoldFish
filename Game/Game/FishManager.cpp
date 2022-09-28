#include "FishManager.h"
#include "BaseObject.h"
#include "Fish.h"
#include "RedFish.h"
#include "BlueFish.h"
#include "GoldFish.h"
#include "BlackFish.h"

// FishManager���̂ւ̃|�C���^��`
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
/// �������i�[����I�u�W�F�N�g�v�[���̍쐬
/// </summary>
/// <param name="redFishSize">��������ԐF�̋����̐�</param>
/// <param name="blueFishSize">��������F�̋����̐�</param>
/// <param name="goldFishSize">����������F�̋����̐�</param>
/// <param name="blackFishSize">�������鍕�F�̋����̐�</param>
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
/// �I�u�W�F�N�g�v�[���ɋ�����ǉ�
/// </summary>
/// <param name="addFish">�ǉ��������</param>
void FishManager::AddFish(Fish* addFish)
{
	mInstance->mFishPool.push_back(addFish);
}

/// <summary>
/// �I�u�W�F�N�g�v�[���̋����̍폜
/// </summary>
/// <param name="removeFish">�폜�������</param>
void FishManager::RemoveFish(Fish* addFish)
{
	mInstance->mFishPool.pop_back();
}

/// <summary>
/// �I�u�W�F�N�g�v�[���̂��ׂĂ̗v�f�̍폜
/// </summary>
void FishManager::RemoveAll()
{
	for (int i = 0; i < mInstance->mFishPool.size(); i++)
	{
		delete mInstance->mFishPool.back();
	}
}

/// <summary>
/// �����蔻����̎擾
/// </summary>
/// <param name="i">�擾����v�f�ԍ�</param>
/// <returns>�����蔻����</returns>
CollisionInfo FishManager::GetCollisionInfo(int i)
{
	mInstance->mCollisionInfo.pos = mInstance->mFishPool[i]->GetPosition();
	mInstance->mCollisionInfo.tag = mInstance->mFishPool[i]->GetTag();

	return mInstance->mCollisionInfo;
}
