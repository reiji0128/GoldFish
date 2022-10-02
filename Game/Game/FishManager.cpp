#include "FishManager.h"
#include "BaseObject.h"
#include "Fish.h"
#include "RedFish.h"
#include "BlueFish.h"
#include "GoldFish.h"
#include "BlackFish.h"

// FishManager���̂ւ̃|�C���^��`
FishManager* FishManager::mInstance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
FishManager::FishManager()
{
	mInstance = nullptr;
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
FishManager::~FishManager()
{
	// �v�[���̑S�v�f�����&�폜
	RemoveAll();
}

/// <summary>
/// �}�l�[�W���[�̃C���X�^���X�쐬
/// </summary>
void FishManager::CreateInstance()
{
	// nullptr�Ȃ琶��
	if (!mInstance)
	{
		mInstance = new FishManager;
	}
}

/// <summary>
/// �}�l�[�W���[�̍폜
/// </summary>
void FishManager::DeleteInstance()
{
	// nullptr�łȂ���Ή��
	if (mInstance)
	{
		delete mInstance;
		mInstance = nullptr;
	}
}

/// <summary>
/// �}�l�[�W���[�̍X�V����
/// </summary>
/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
void FishManager::Update(float deltaTime)
{
	for (auto pool : mInstance->mFishPool)
	{
		pool->Update(deltaTime);
	}
}

/// <summary>
/// �`�揈��
/// </summary>
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
	// �ԐF�̋����̒ǉ�
	for (int i = 0; i < redFishSize; i++)
	{
		mInstance->mRedFish = new RedFish(Tag::RedFish);
		AddFish(mInstance->mRedFish);
	}

	// �F�̋����̒ǉ�
	for (int i = 0; i < blueFishSize; i++)
	{
		mInstance->mBlueFish = new BlueFish(Tag::BlueFish);
		AddFish(mInstance->mBlueFish);
	}

	// ���F�̋����̒ǉ�
	for (int i = 0; i < goldFishSize; i++)
	{
		mInstance->mGoldFish = new GoldFish(Tag::GoldFish);
		AddFish(mInstance->mGoldFish);
	}

	// ���F�̋����̒ǉ�
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
	// �v�[���̍Ō�̗v�f��delete������ɍ폜
	while (!mInstance->mFishPool.empty())
	{
		delete mInstance->mFishPool.back();
		mInstance->mFishPool.pop_back();
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
