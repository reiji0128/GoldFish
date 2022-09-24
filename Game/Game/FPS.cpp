#include "FPS.h"
#include "DxLib.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
FPS::FPS()
    // �t���[�����[�g�̍ō��l�̏�����.
	: MSetFps(60)
	// 1�t���[���ɂ����鎞��.
	, MOneFrameTickCount(1000 / MSetFps)
	// �P�O�̃t���[���̂�����������.
	, mBeforeTickCount(0)
	// ���݂̃t���[���̂�����������.
	, mDeltaTime(0)
{
}

/// <summary>
/// �X�V����.
/// </summary>
void FPS::Update()
{
	// fps����l���傫���Ȃ�Ȃ��悤�ɂ��鏈��.
	Wait();

	// �f���^�^�C���̌v�Z.
	mDeltaTime = (GetNowCount() - mBeforeTickCount) / 1000.0f;

	// �f���^�^�C���𐧌�.
	if (mDeltaTime >= 0.10f)
	{
		// �f���^�^�C����0.10f�ɐݒ肷��.
		mDeltaTime = 0.10f;
	}

	// �O�t���[���Ƃ��Ă����܂ł����������Ԃ�ۑ�����.
	mBeforeTickCount = GetNowCount();
}

/// <summary>
/// fps����l���傫���Ȃ�Ȃ��悤�ɂ���֐�.
/// </summary>
void FPS::Wait()
{
	// ���ݒl��1�t���[���ɂ����鎞�Ԃ𒴂���܂ŌJ��Ԃ�
	while (GetNowCount() < mBeforeTickCount + MOneFrameTickCount);
}
