#pragma once

class Fish;

class FishStaeBase
{
public:

	FishStaeBase() {};

	~FishStaeBase() {};


	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="owner">�v���C���[�̃|�C���^</param>
	/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
	/// <returns>�v���C���[�̏��</returns>
	virtual FishState Update(Fish* owner, float deltaTime) = 0;

	/// <summary>
	/// ��Ԃ��ڍs�����Ƃ���1�x�������鏈��
	/// </summary>
	/// <param name="owner">�v���C���[�̃|�C���^</param>
	/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
	virtual void Enter(Fish* owner, float deltaTime) {};

};