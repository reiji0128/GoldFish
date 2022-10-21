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
const char* ButtonImgName[ButtonImgFileNum::MaxBtnFileNum] =
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
	None = 0,
	Start,
	Retry,
	Exit,

	MaxStateNum,
};

/// <summary>
/// �{�^���摜�⏈�����s���N���X.
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

	/// <summary>
	/// �`��֐��A�I�[�o�[���C�h�֐�.
	/// </summary>
	void Draw() override;

private:
	BtnState mState;                     // ���ꂼ��̃{�^���ɐU�蕪�����Ă���X�e�[�^�X��ۑ�����ϐ�.

	bool mChangeSceneFlag;               // �V�[���ړ��t���O�Atrue�̎��̓V�[����ς���false�̎��̓V�[����ς��Ȃ�.
	bool mGameExitFlag;                  // �Q�[���I���t���O�Atrue�̎��̓Q�[�����I��������false�̎��̓Q�[���𑱂���.

	// ��x�L�[�����������ǂ����̃t���O�i�������h�~�p�t���O�j�Atrue�̎��̓L�[����x�������Ƃ���false�̎��̓L�[�������Ă��Ȃ��Ƃ���.
	bool mPushBtnFlag; 

public:// ------------------�Z�b�^�[�E�Q�b�^�[�֐�-------------------------

	/// <summary>
	/// ���݂̃V�[����ς���t���O���擾����֐�.
	/// </summary>
	/// <returns>bool�^�̃V�[���ړ��t���O��Ԃ�.</returns>
	bool GetChangeSceneFlag() { return mChangeSceneFlag; }
};