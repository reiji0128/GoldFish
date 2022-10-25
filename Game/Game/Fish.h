#pragma once
#include "BaseObject.h"
#include <vector>

class FishStateBase;

enum class State
{
	Active,
	Inacive
};

class Fish : public BaseObject
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="tag">1�t���[���̌o�ߎ���</param>
	Fish(Tag tag);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Fish();

	void Init();

	/// <summary>
	/// �`�揈��
	/// </summary>
	virtual void Draw() {};

	/// <summary>
	/// �~�܂��Ă��鏈��
	/// </summary>
	void StopProces();

	// �����g�̓���
	void MoveSinWave();

// �Z�b�^�[ //

	void SetMovement(float paramerter1, float parameter2,float angle);

// �Q�b�^�[�@//

	/// <summary>
	/// ���݂̏�Ԃ̎擾
	/// </summary>
	/// <returns>���݂̏��</returns>
	State const GetState() { return mNowState; }

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

	// �����g��X
	float mSinWaveX;
	// �����g�̊p�x
	float mSinWaveAngle;
	// �U��
	float mAmplitude;
	// �g��
	float mWwaveLength;

	// �X�s�[�h
	float mSpeed;
	float mXerr;
	float mYerr;

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

	const Vector2 mWindowLeftUpPos = Vector2(0, 0);
	const Vector2 mWindowRightDownPos = Vector2(1920, 1080);

	// ���݂̏��
	State mNowState;
};
