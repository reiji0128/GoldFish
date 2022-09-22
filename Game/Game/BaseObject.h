#pragma once
#include "Math.h"
#include "Tag.h"

class BaseObject
{
public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	BaseObject(const Tag tag);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~BaseObject();

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
	void Update(float deltaTime);

	/// <summary>
	/// �I�u�W�F�N�g�̍X�V����
	/// </summary>
	/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
	virtual void UpdateObject(float deltaTime);

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

// �Q�b�^�[ //

	/// <summary>
	/// ���W�̎擾
	/// </summary>
	/// <returns>���W</returns>
	const Vector2& GetPosition() const { return mPosition; }

	/// <summary>
	/// �X�P�[���̎擾
	/// </summary>
	/// <returns>�X�P�[��</returns>
	const Vector2& GetScale() const { return mScale; }

	/// <summary>
	/// �p�x�̎擾
	/// </summary>
	/// <returns>�p�x</returns>
	const float& GetAngle() const { return mAngle; }

	/// <summary>
	///  �^�O�̎擾
	/// </summary>
	/// <returns>�I�u�W�F�N�g�̃^�O</returns>
	Tag GetTag() const { return mTag; }

// �Z�b�^�[ //

	/// <summary>
	/// ���W�̃Z�b�g
	/// </summary>
	/// <param name="position">�Z�b�g������W</param>
	void SetPosition(const Vector2& position) { mPosition = position; }

	/// <summary>
	/// �X�P�[���̃Z�b�g
	/// </summary>
	/// <param name="scale">�Z�b�g����X�P�[��</param>
	void SetScale(const Vector2& scale) { mScale = scale; }

	/// <summary>
	/// �p�x�̃Z�b�g
	/// </summary>
	/// <param name="angle">�Z�b�g����p�x</param>
	void SetAngle(const float& angle) { mAngle = angle; }

protected:
	// ���W
	Vector2 mPosition;

	// �X�P�[��
	Vector2 mScale;

	// �p�x
	float mAngle;

	// �I�u�W�F�N�g�̃^�O
	Tag mTag;
};