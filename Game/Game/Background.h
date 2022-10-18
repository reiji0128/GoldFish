#pragma once
#include "Math.h"

/// <summary>
/// �摜�t�@�C���̏���.
/// </summary>
enum BgImgFileNum : unsigned short
{
	NoneBg = 0,
	TitleBg,
	PlayBg,
	ResultBg,

	MaxBgNum,
};

// ��L��enum�N���X�̏��Ԃŉ摜�p�X��ۑ�����ۑ��ϐ�.
static const char* BgImgName[BgImgFileNum::MaxBgNum] =
{
	"Img/Bg/none.png",
	"Img/Bg/Title.png",
	"Img/Bg/Play.png",
	"Img/Bg/Result.png",
};

/// <summary>
/// �w�i�N���X.
/// </summary>
class Background
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	Background(const char* fileName);

	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~Background();

	/// <summary>
	/// �X�V�֐�.
	/// </summary>
	void Update();

	/// <summary>
	/// �`��֐�.
	/// </summary>
	void Draw();

private:
	Vector2 mPos;               // ���W�ۑ��ϐ�.
	Vector2 mScale;             // �摜�̑傫���̕ۑ��ϐ�.
	int mImgHandle;             // �摜�n���h���ۑ��ϐ�.

public:// ---------�Z�b�^�[�E�Q�b�^�[�֐�--------------
	
	/// <summary>
	/// �w�i�摜�̍��W��ݒ肷��֐�.
	/// </summary>
	/// <param name="pos">Vector2�^��pos.</param>
	void SetPosition(Vector2 pos)
	{
		mPos = pos;
	}

	/// <summary>
	/// ���݂̍��W��Ԃ�.
	/// </summary>
	/// <returns>Vector2�^�̕ϐ���Ԃ�.</returns>
	Vector2 GetPosition()
	{
		return mPos;
	}

	/// <summary>
	/// ���݂̉摜�T�C�Y��Ԃ�.
	/// </summary>
	/// <returns>Vector2�^�̕ϐ���Ԃ�.</returns>
	Vector2 GetScale()
	{
		return mScale;
	}
};