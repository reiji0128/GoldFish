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

// �O���錾
class Fish;
class RedFish;
class BlueFish;
class GoldFish;
class BlackFish;

class FishManager final
{
public:
	FishManager();

	~FishManager();

	/// <summary>
	/// �������i�[����I�u�W�F�N�g�v�[���̍쐬
	/// </summary>
	/// <param name="redFishSize">��������ԐF�̋����̐�</param>
	/// <param name="blueFishSize">��������F�̋����̐�</param>
	/// <param name="goldFishSize">����������F�̋����̐�</param>
	/// <param name="blackFishSize">�������鍕�F�̋����̐�</param>
	void CreatePool(const int redFishSize,
					const int blueFishSize,
					const int goldFishSize,
	                const int blackFishSize);

	/// <summary>
	/// �I�u�W�F�N�g�v�[���ɋ�����ǉ�
	/// </summary>
	/// <param name="addFish">�ǉ��������</param>
	void AddFish(Fish* addFish);

	/// <summary>
	/// �I�u�W�F�N�g�v�[���̋����̍폜
	/// </summary>
	/// <param name="removeFish">�폜�������</param>
	void RemoveFish(Fish* removeFish);

	/// <summary>
	/// �I�u�W�F�N�g�v�[���̂��ׂĂ̗v�f�̍폜
	/// </summary>
	void RemoveAll();

// �Q�b�^�[ //

	/// <summary>
	/// �����蔻����̎擾
	/// </summary>
	/// <param name="i">�擾����v�f�ԍ�</param>
	/// <returns>�����蔻����</returns>
	CollisionInfo GetCollisionInfo(int i);

private:
	// �����蔻����
	CollisionInfo mCollisionInfo;

	// �����̃I�u�W�F�N�g�v�[��
	std::vector<Fish*> mFishPool;

	RedFish* mRedFish;
	BlueFish* mBlueFish;
	GoldFish* mGoldFish;
	BlackFish* mBlackFish;
};
