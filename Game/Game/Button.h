#pragma once
#include "Math.h"
#include "Image.h"

/// <summary>
/// �摜�t�@�C���̏���.
/// </summary>
enum ButtonImgFileNum : unsigned short
{
	NoneBtn = 0,              // �{�^���摜�������Ȃ���.
	StartBtn,                 // �{�^���摜���n�߂鎞.
	ExitBtn,                  // �{�^���摜�����鎞.
	TutorialSkip,             // �{�^���摜���`���[�g���A�����X�L�b�v�̎�.
	TitleBtn,                 // �{�^���摜���^�C�g���̎�.

	MaxBtnFileNum,            // �{�^���摜�̍ő喇��.
};

// ��L��enum�N���X�̏��Ԃŉ摜�t�@�C���p�X��ۑ�����ϐ�.
static const char* ButtonImgName[ButtonImgFileNum::MaxBtnFileNum] =
{
	"img/None.png",                     // �����Ȃ����̉摜�t�@�C���p�X.
	"img/Button/Start.png",             // �n�߂鎞�̉摜�t�@�C���p�X.
	"img/Button/Exit.png",              // ���鎞�̉摜�t�@�C���p�X.
	"img/Button/TutorialSkip2.png",     // �X�L�b�v�̉摜�t�@�C���p�X.
	"img/Button/Title.png",             // �^�C�g���̉摜�t�@�C���p�X.
};

/// <summary>
/// enumClass�̃{�^���̃X�e�[�^�X�A�^��unsigned short.
/// </summary>
enum class BtnState :unsigned short
{
	None = 0,                 // �I���}�E�X�����摜�������Ȃ���.
	Start,                    // �I���}�E�X�����摜���X�^�[�g�̎�.
	Retry,                    // �I���}�E�X�����摜�����g���C�̎�.
	Exit,                     // �I���}�E�X�����摜���Q�[���I���̎�.
	TutoSkip,                 // �I���}�E�X�����摜���`���[�g���A�����X�L�b�v���鎞.
	Title,                    // �I���}�E�X�����摜���^�C�g���̎�.

	MaxStateNum,              // �{�^���X�e�[�^�X�̍ő吔.
};

/// <summary>
/// �{�^���������s���N���X.
/// Image�N���X���p��.
/// </summary>
class Button : public Image
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="fileName">const char*�^�̃{�^���摜�̃t�@�C���p�X.</param>
	Button(const char* fileName, BtnState state);

	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~Button();

	/// <summary>
	/// �X�V�֐��A�I�[�o�[���C�h�֐�.
	/// </summary>
	/// <param name="deltaTime">float�^�̃f���^�^�C���̈���.</param>
	void Updata(float deltaTime, ViewState state) override;

private:
	BtnState mState;                     // ���ꂼ��̃{�^���ɐU�蕪�����Ă���X�e�[�^�X��ۑ�����ϐ�.
	float mRad;                          // �㉺�̓���������ۂ̐U�ꕝ�̑傫��(float�^).
	const float M_SPEED;                 // �㉺�̓����̃X�s�[�h(const float�^).

public:// ------------------�Z�b�^�[�E�Q�b�^�[�֐�-------------------------
	/// <summary>
	/// ���̃{�^���̃X�e�[�^�X���擾����֐�.
	/// </summary>
	/// <returns>BtnState�N���X�̕ϐ�.</returns>
	BtnState GetBtnState() { return mState; }
};