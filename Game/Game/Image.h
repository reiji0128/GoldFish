#pragma once
#include "Math.h"

/// <summary>
/// �摜�t�@�C���̏���.
/// </summary>
static enum class ImgFileNum :short
{
	NONE_IMG = 0,
	TITLE_IMG,
	PLAY_IMG,
	RESULT_IMG,

	MAX_IMG_FILE_NUM,
};

// ��L��enum�N���X����
static const char* MapPicName[] =
{
	"img/none.png",
};

/// <summary>
/// �摜�N���X.
/// 
/// </summary>
class Image
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	Image(const char* fileName);

	/// <summary>
	/// �f�X�g���N�^�A���z�֐�.
	/// </summary>
	virtual ~Image();

	/// <summary>
	/// �X�V�֐��A���z�֐�.
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// �`��֐��A���z�֐�.
	/// </summary>
	virtual void Draw() = 0;

private:
	Vector2 mPos;          // ���W�ۑ��֐�.
	Vector2 mScale;        // �摜�T�C�Y�ۑ��ϐ�.
	int     mImgHandle;    // �摜�n���h���ۑ��ϐ�.

public://--------------�Z�b�^�[�E�Q�b�^�[------------------//
	
	/// <summary>
	/// �w�i�摜�̍��W��ݒ肷��֐�.
	/// </summary>
	/// <param name="pos">Vector2�^�̍��W.</param>
	void SetPosition(Vector2 pos)
	{
		mPos = pos;
	}

	/// <summary>
	/// �摜�̍��W���擾����֐�.
	/// </summary>
	/// <returns></returns>
	Vector2 GetPosition()
	{
		return mPos;
	}

	/// <summary>
	/// �摜�T�C�Y���擾����֐�.
	/// </summary>
	/// <returns>Vector2�^�̑傫��.</returns>
	Vector2 GetScale()
	{
		return mScale;
	}
};