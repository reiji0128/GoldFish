#pragma once
#include "SceneBase.h"
#include "FPS.h"
#include "PoiRed.h"
#include "PoiBlue.h"

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
	~GameManager() {};

	/// <summary>
	/// ����������.
	/// </summary>
	/// <returns>�Ԃ�l��true�̎��͐����Afalse�̎��͎��s.</returns>
	bool Initialize();

	/// <summary>
	/// �Q�[�����[�v.
	/// </summary>
	void GameLoop();

	/// <summary>
	/// �I������.
	/// </summary>
	void terminate();

private:
	/// <summary>
	/// mReturnTag���g�p�����V�����V�[���𐶐�����֐�.
	/// </summary>
	void CreateScene();

	/// <summary>
	/// ���͏����֐�.
	/// </summary>
	void ProcessInput();

	/// <summary>
	/// �Q�[���̍X�V����.
	/// </summary>
	void UpdateGame();

	/// <summary>
	/// �Q�[���̕`�揈��.
	/// </summary>
	void DrawGame();

	// �R���X�^���g�ϐ�.
	const int MWidth;
	const int MHeight;
	const int MColorBitNum;

	// ���[�v�𔲂��邩�ǂ�����bool�^�ϐ��Atrue�̏ꍇ�̓��[�v�𑱂���Afalse�̏ꍇ�̓��[�v�𔲂���.
	bool mRunningFlag;

	// ���݂̃V�[���N���X�����ϐ�.
	SceneBase* mNowScene;

	// �P���[�v�O�̃V�[���^�O��ۑ�����ϐ�.
	SceneBase::SceneTag mReturnTag;

	// FPS�N���X�����ϐ�.
	FPS* mFps;

public:// ------------------�Z�b�^�[�E�Q�b�^�[�֐�-------------------------

	/// <summary>
	/// �ŏ��̃V�[���̑��.
	/// </summary>
	/// <param name="firstScene">SceneBase�^�̈�ԍŏ��ɕ\������V�[��.</param>
	void SetFirstScene(SceneBase* firstScene)
	{
		// ���݂̃V�[���ւƑ������.
		mNowScene = firstScene;
	};
};

