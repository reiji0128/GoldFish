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

	void StopProces();
	void SwimProces();
	void TurnProces();
protected:
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
	// �o�ߎ���(�b)
	const int mElapsedSecond = 2;
	// �ڕW�p�x
	const int mTargetAngle = 45;
	// �j���ł��Ԃ�
	bool mIsSwim;
	// ���݂̏��
	FishState mNowState;
};
