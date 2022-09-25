#pragma once
#include "BaseObject.h"
#include <vector>

class FishStateBase;

enum class FishState
{
	Stop,
	Swim,
	Turn
};

class Fish : public BaseObject
{
public:
	Fish(Tag tag);
	~Fish();

	/// <summary>
	/// �~�܂��Ă��鏈��
	/// </summary>
	void StopProces();

	/// <summary>
	/// �j������
	/// </summary>
	void SwimProces();

	/// <summary>
	/// �Ȃ��鏈��
	/// </summary>
	void TurnProces();

protected:

	/// <summary>
	/// �������ꂽ���W�𒴂��������ׂ�֐�
	/// </summary>
	/// <returns>
	/// true  : �������ꂽ���W�𒴂���
	/// false : �������ꂽ���W�𒴂��Ă��Ȃ�
	/// </returns>
	bool OverLimitPos();

	// �A�j���[�V�����O���t�n���h��
	int mGraphHandle[8];
	// �J�n���̃^�C��
	int mStartTime;
	// ���݂̃^�C��
	int mNowTime;
	// �o�ߎ���
	int mElapsedTime;
	// ���݂̃J�E���g
	int mNowCount;
	// �A�j���[�V�����J�E���g
	int mAnimationCount;
	// �X�e�[�g�̔ԍ�
	int mStateNumber;
	// �ڕW����(�b)
	const int mTargetTime = 2;
	// �ڕW�p�x
	int mTargetAngle;
	// �j���ł��Ԃ�
	bool mIsSwim;
	// ���W�̍ŏ��l(��ʂ���o�Ȃ��悤��0���傫���l)
	const int mMinPosX = 100;
	const int mMinPosY = 100;
	// ���W�̍ő�l(��ʂ���o�Ȃ��悤�Ƀt���X�N���[���̃T�C�Y��菬�����l)
	const int mMaxPosX = 1900;
	const int mMaxPosY = 1750;
	// ���݂̏��
	FishState mNowState;
};
