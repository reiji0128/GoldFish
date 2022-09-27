#pragma once
#include "SceneBase.h"
#include "FPS.h"
#include "Poi.h"

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

	const int MWidth;
	const int MHeight;
	const int MColorBitNum;

	bool mRunningFlag;

	SceneBase* mNowScene;
	SceneBase::SceneTag mReturnTag;

	FPS* mFps;

	Poi* mPoi1;
	Poi* mPoi2;

public:
	void SetFirstScene(SceneBase* firstScene)
	{
		mNowScene = firstScene;
	};
};

