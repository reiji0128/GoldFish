#pragma once

//------------------------------
// �����ɃQ�[���v���C���ɕK�v�ȃw�b�_�[���C���N���[�h���Ă�������.


/// <summary>
/// �Q�[���}�l�[�W���[�N���X.
/// </summary>
class GameManager
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	GameManager();

	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~GameManager();

	/// <summary>
	/// �X�V�֐�.
	/// </summary>
	/// <param name="deltaTime">float�^�̃f���^�^�C���̈���.</param>
	void Update(float deltaTime);

	/// <summary>
	/// �`��֐�.
	/// </summary>
	void Draw();

private:
};

