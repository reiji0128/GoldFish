#pragma once
#include "BaseObject.h"
#include "Tag.h"

/// <summary>
/// �|�C�N���X
/// BaseObject���p�����Ă���
/// </summary>
class Poi : public BaseObject
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Poi(Tag tag, const int num);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Poi();

	/// <summary>
	/// �I�u�W�F�N�g�̍X�V����
	/// </summary>
	/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
	void UpdateObject(float deltaTime)override;

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

private:
	/// <summary>
	/// �ړ�����
	/// </summary>
	/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
	void Move(float deltaTime);

	/// <summary>
	/// �ʒu��������
	/// </summary>
	void AdjustPosition();

	/// <summary>
	/// �{�[�i�X�^�C������
	/// </summary>
	/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
	void BonusTime(float deltaTime);

	/// <summary>
	/// �d������
	/// </summary>
	/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
	void Scoop(float deltaTime);

	/// <summary>
	/// �̗͊m�F����
	/// </summary>
	void CheckHP();

	/// <summary>
	/// �X�R�A�v�Z��HP����
	/// </summary>
	/// <param name="tag">�����̎��</param>
	void CalcScoreAndHP(Tag tag);

	/// <summary>
	/// �|�C�C��
	/// </summary>
	/// <param name="deltaTime"></param>
	void PoiRepair(float deltaTime);

	/// <summary>
	/// �����蔻��
	/// </summary>
	void Coll();

	// �X�P�[���i�ϓ��p�j
	float mFloatScale;

	// ���̃X�P�[���̔���
	float mHalfScaleX;
	float mHalfScaleY;

	// �R���g���[���[�̓��͏��
	int mPadNum;
	int mInputX;
	int mInputY;

	// ���x
	float mSpeed;

	// �摜
	int mImage;

	// �j�ꍷ��
	int mBreakImg[5];

	// �d������
	int mScoopImg[3];

	// �d���Ă��邩�ǂ���
	bool mIsScoop;

	// 1�t���[���ڂ��ǂ���
	bool mIsFirstFrame;

	// �O�t���[���ł̓��͂��Ă������ǂ���
	bool mPrevInputA;

	// �A�j���[�V�����p
	float mAnimCounter;
	int mAnimNum;

	// �{�[�i�X�p
	bool mIsBonus;
	int mBonusCount;
	float mBonusCounter;

	// �|�C�̑ϋv�l
	int mPoiHP;

	// �|�C�������Ă邩�ǂ���
	bool mAlive;

	float deadTime;

	// �X�R�A
	int mScore;

};