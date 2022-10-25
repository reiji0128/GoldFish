#include "BlueFish.h"
#include <DxLib.h>
#include "Math.h"

BlueFish::BlueFish(Tag tag)
	:Fish(tag)
{
	// �摜�̓ǂݍ���
	LoadDivGraph("Assets/GoldFish/GoldFish_Blue.png", 8, 8, 1, 128, 128, mGraphHandle);

	// �J�n���̎��Ԃ��擾
	mStartTime = GetNowCount() / 1000;
}

BlueFish::~BlueFish()
{
}

void BlueFish::UpdateObject(float deltaTime)
{
	// �����g���g�����ړ�����
	MoveSinWave();

	// ��ʊO�ɏo�����Ԃ��A�N�e�B�u�ɕύX
	if (OverLimitPos())
	{
		mNowState = State::Inacive;
	}
}

void BlueFish::Draw()
{
	// ���݂̃J�E���^����A�j���[�V�����̕\������n���h�����Z�o
	mNowCount = GetNowCount();
	mAnimationCount = mNowCount / 120 % 8;

	// �摜�̕\��
	DrawRotaGraph(mPosition.x, mPosition.y, 1.0, mAngle, mGraphHandle[mAnimationCount], true);
}
