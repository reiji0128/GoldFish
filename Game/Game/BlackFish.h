#pragma once
#include "Fish.h"

class BlackFish : public Fish
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="tag">�I�u�W�F�N�g�̃^�O</param>
	BlackFish(Tag tag);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~BlackFish();

	/// <summary>
	/// �I�u�W�F�N�g�̍X�V����
	/// </summary>
	/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
	void UpdateObject(float deltaTime) override;

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw() override;
};
