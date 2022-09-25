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
	/// <summary>
	/// �C���X�^���X�̍쐬
	/// </summary>
	static void CreateInstance();

	/// <summary>
	/// �C���X�^���X�̍폜
	/// </summary>
	static void DeleteInstance();

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
	static void Update(float deltaTime);

	/// <summary>
	/// �`�揈��
	/// </summary>
	static void Draw();

	/// <summary>
	/// �������i�[����I�u�W�F�N�g�v�[���̍쐬
	/// </summary>
	/// <param name="redFishSize">��������ԐF�̋����̐�</param>
	/// <param name="blueFishSize">��������F�̋����̐�</param>
	/// <param name="goldFishSize">����������F�̋����̐�</param>
	/// <param name="blackFishSize">�������鍕�F�̋����̐�</param>
	static void CreatePool(const int redFishSize,
					const int blueFishSize,
					const int goldFishSize,
	                const int blackFishSize);

	/// <summary>
	/// �I�u�W�F�N�g�v�[���ɋ�����ǉ�
	/// </summary>
	/// <param name="addFish">�ǉ��������</param>
	static void AddFish(Fish* addFish);

	/// <summary>
	/// �I�u�W�F�N�g�v�[���̋����̍폜
	/// </summary>
	/// <param name="removeFish">�폜�������</param>
	static void RemoveFish(Fish* removeFish);

	/// <summary>
	/// �I�u�W�F�N�g�v�[���̂��ׂĂ̗v�f�̍폜
	/// </summary>
	static void RemoveAll();

// �Q�b�^�[ //

	/// <summary>
	/// �����蔻����̎擾
	/// </summary>
	/// <param name="i">�擾����v�f�ԍ�</param>
	/// <returns>�����蔻����</returns>
	CollisionInfo GetCollisionInfo(int i);

private:
	/// <summary>
	/// �V���O���g��
	/// </summary>
	FishManager();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~FishManager();

	// �}�l�[�W���[�̎���
	static FishManager* mInstance;

	// �����蔻����
	CollisionInfo mCollisionInfo;

	// �����̃I�u�W�F�N�g�v�[��
	std::vector<Fish*> mFishPool;

	RedFish* mRedFish;
	BlueFish* mBlueFish;
	GoldFish* mGoldFish;
	BlackFish* mBlackFish;
};
