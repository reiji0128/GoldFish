#pragma once

/* �t���[���ɂ����������Ԃ��v���������݂���N���X */
class FPS
{
public:
	// �R���X�g���N�^
	FPS();
	// �f�X�g���N�^
	~FPS() {};

	// �t���[�����̍X�V����
	void Update();

private:
	// FPS���ݒ�l���傫���Ȃ�Ȃ��悤�ɐ��䂷��֐�.
	void Wait();

	const int MSetFps;             // �t���[�����[�g�̍ō��l
	const int MOneFrameTickCount;  // 1�t���[���ɂ����鎞��

	int mBeforeTickCount;     // �O�̃t���[���̂�����������
	float mDeltaTime;         // ���݂̃t���[���̂�����������

public:   // �Q�b�^�[�A�Z�b�^�[
	// ���݂̃t���[���ɂ�����������(float�^)
	float GetDeltaTime() { return mDeltaTime; }
};

