#pragma once
#include "Math.h"

/// <summary>
/// �摜�t�@�C���̏���.
/// </summary>
static enum BgImgFileNum
{
	NONE_IMG = 0,
	TITLE_IMG,
	PLAY_IMG,
	RESULT_IMG,

	MAX_IMG_FILE_NUM,
};

// ��L��enum�N���X����
static const char* BgImgName[BgImgFileNum::MAX_IMG_FILE_NUM] =
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
	Vector2 mVec;               // �摜�ړ��ۑ��ϐ�.
	bool mMoveFlag;             // �摜�ړ��t���O�ۑ��ϐ�.

public:// ---------�Z�b�^�[�E�Q�b�^�[�֐�--------------
	
	/// <summary>
	/// �w�i�摜�̍��W��ݒ肷��֐�.
	/// </summary>
	/// <param name="pos">Vector2�^��pos.</param>
	void SetPosition(Vector2 pos)
	{
		mPos = pos;
	}

	Vector2 GetPosition()
	{
		return mPos;
	}

	Vector2 GetScale()
	{
		return mScale;
	}
};