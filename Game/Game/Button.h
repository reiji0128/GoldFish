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
/// enumClass�̃{�^���̃X�e�[�^�X�A�^��unsigned short.
/// </summary>
enum class BtnState :unsigned short
{
	None = 0,                 // �I���}�E�X�����摜�������Ȃ���.
	Start,                    // �I���}�E�X�����摜���X�^�[�g�̎�.
	Retry,                    // �I���}�E�X�����摜�����g���C�̎�.
	Exit,                     // �I���}�E�X�����摜���Q�[���I���̎�.

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
	void Updata(float deltaTime) override;

	///// <summary>
	///// ���͏����֐�.
	///// </summary>
	//void Input(BtnState state);

	/// <summary>
	/// �`��֐��A�I�[�o�[���C�h�֐�.
	/// </summary>
	void Draw() override;

private:
	BtnState mState;                     // ���ꂼ��̃{�^���ɐU�蕪�����Ă���X�e�[�^�X��ۑ�����ϐ�.

	//// ��x�L�[�����������ǂ����̃t���O�i�������h�~�p�t���O�j�Atrue�̎��̓L�[����x�������Ƃ���false�̎��̓L�[�������Ă��Ȃ��Ƃ���.
	//bool mPushedBtnFlag; 

public:// ------------------�Z�b�^�[�E�Q�b�^�[�֐�-------------------------
	/// <summary>
	/// ���̃{�^���̃X�e�[�^�X���擾����֐�.
	/// </summary>
	/// <returns>BtnState�N���X�̕ϐ�.</returns>
	BtnState GetBtnState() { return mState; }

	///// <summary>
	///// �{�^����������Ă��邩�ǂ����̃t���O��ݒ肷��֐�.
	///// </summary>
	///// <param name="flag">�ݒ肷��bool�^�ϐ��܂��͐^�U�l.</param>
	//void SetPushedBtnFlag(bool flag) { mPushedBtnFlag = flag; }

	///// <summary>
	///// �{�^����������Ă��邩�ǂ����̃t���O���擾����֐�.
	///// </summary>
	///// <returns>���݂��̃{�^����������Ă���Ƃ���true�A������Ă��Ȃ��Ƃ���false��Ԃ�.</returns>
	//bool GetPushedBtnFlag() { return mPushedBtnFlag; }
};