#pragma once
#include "Math.h"
#include "ImageBase.h"

/// <summary>
/// �摜�t�@�C���̏���.
/// </summary>
enum ButtonImgFileNum : unsigned short
{
	NoneBtn = 0,              // �{�^���摜�������Ȃ���.
	StartBtn,                 // �{�^���摜���n�߂鎞.
	ExitBtn,                  // �{�^���摜�����鎞.

	MaxBtnFileNum,            // �{�^���摜�̍ő喇��.
};

// ��L��enum�N���X�̏��Ԃŉ摜�t�@�C���p�X��ۑ�����ϐ�.
static const char* ButtonImgName[ButtonImgFileNum::MaxBtnFileNum] =
{
	"img/Button/None.png",    // �����Ȃ����̉摜�t�@�C���p�X.
	"img/Button/Start.png",   // �n�߂鎞�̉摜�t�@�C���p�X.
	"img/Button/Exit.png",    // ���鎞�̉摜�t�@�C���p�X.
};

/// <summary>
/// �{�^���摜�⏈�����s���N���X.
/// </summary>
class Button : public ImageBase
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="fileName">const char*�^�̃{�^���摜�̃t�@�C���p�X.</param>
	Button(const char* fileName);

	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~Button();

	/// <summary>
	/// �X�V�֐��A�I�[�o�[���C�h�֐�.
	/// </summary>
	/// <param name="deltaTime">float�^�̃f���^�^�C���̈���.</param>
	void Updata(float deltaTime) override;

	/// <summary>
	/// �`��֐��A�I�[�o�[���C�h�֐�.
	/// </summary>
	void Draw() override;

private:
};