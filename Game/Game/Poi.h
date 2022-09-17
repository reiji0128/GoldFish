#pragma once
#include "BaseObject.h"

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
	Poi(const int num);

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

	// ���W
	float mPositionX;
	float mPositionY;

	// �X�P�[���i�ϓ��p�j
	float mScale;

	// �X�P�[��
	float mScaleX;
	float mScaleY;

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
	//float mBonusCounter;

	// �|�C�̑ϋv�l
	int mPoiHP;

};