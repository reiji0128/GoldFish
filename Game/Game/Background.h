#pragma once
#include "Math.h"
#include "Image.h"

/// <summary>
/// �摜�t�@�C���̏���.
/// </summary>
enum BgImgFileNum : unsigned short
{
	NoneBg = 0,      // �w�i�������Ȃ���.
	TitleBg,         // �w�i���^�C�g���̎�.
	TutorialBg,      // �w�i���`���[�g���A���̎�.
	PlayBg,          // �w�i���v���C�̎�.
	ResultBg,        // �w�i�����U���g�̎�.

	MaxBgNum,        // �w�i�摜�̍ő喇��.
};

// ��L��enum�N���X�̏��Ԃŉ摜�t�@�C���p�X��ۑ�����ϐ�.
static const char* BgImgName[BgImgFileNum::MaxBgNum] =
{
	"Img/Bg/None.png",       // �����Ȃ����̉摜�t�@�C���p�X.
	"Img/Bg/Title.png",      // �^�C�g�����̉摜�t�@�C���p�X.
	"Img/Bg/Tutorial.png",   // �`���[�g���A�����̉摜�t�@�C���p�X.
	"Img/Bg/Play.png",       // �v���C���̉摜�t�@�C���p�X.
	"Img/Bg/Result.png",     // ���U���g���̉摜�t�@�C���p�X.
};

/// <summary>
/// �w�i�N���X.
/// </summary>
class Background : public Image
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
 	void Updata(float deltaTime) override;

	/// <summary>
	/// �`��֐�.
	/// </summary>
	void Draw() override;
};