#pragma once
#include "Math.h"

/// <summary>
/// �摜�t�@�C���̏���.
/// </summary>
static enum BackgroundFileNum
{
	NONE_IMG = 0,
	TITLE_IMG,
	PLAY_IMG,
	RESULT_IMG,

	MAX_IMG_FILE_NUM,
};

static const char* MapPicName[MAX_IMG_FILE_NUM] =
{
	"img/none.png",
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
	/// �摜�̉����̎擾�֐�.
	/// </summary>
	/// <returns>int�^�̉摜�̉���.</returns>
	int GetImgWidth()
	{
		return mWidth;
	}

	/// <summary>
	/// �摜�̏c���̎擾�֐�.
	/// </summary>
	/// <returns>int�^�̉摜�̏c��.</returns>
	int GetImgHeight()
	{
		return mHeight;
	}
};