#include "GameManager.h"
#include "DxLib.h"

#include "Title.h"
#include "Tutorial.h"
#include "Play.h"
#include "Result.h"
#include "Exit.h"

#include "FishManager.h"
#include "PoiManager.h"
//-----------------�K�v�Ȏ��Ƀw�b�_�[�t�@�C�����C���N���[�h���Ă�������.-------------------//

/// <summary>
/// �R���X�g���N�^.
/// </summary>
GameManager::GameManager()
	:MColorBitNum(16)                         // �E�B���h�E�̃J���[�r�b�g�̐�.
	,mRunningFlag(true)                       // �Q�[�����[�v���񂷂��ǂ�����ۑ�����t���O�Atrue�Ȃ烋�[�v�����false�Ȃ烋�[�v���甲����.
	,mNowSceneClass(nullptr)                  // ���݂̃V�[���N���X��ۑ�����ϐ�.
	,mReturnTag(SceneBase::mNowSceneTag)      // ���̃V�[���̃^�O��ۑ�����ϐ�.
	,mFps(nullptr)                            // fps�N���X��ۑ�����ϐ�.
{
}

/// <summary>
/// ����������.
/// </summary>
/// <returns>�������������true���A���s�����false���Ԃ��Ă���.</returns>
bool GameManager::Initialize()
{
	// �E�B���h�E�̃T�C�Y�ƃJ���[�r�b�g���w�肷��.
	SetGraphMode(MWidth, MHeight, MColorBitNum);

	// �t���X�N���[��������邽�߁A�E�B���h�E���[�h�ɂ���.
	ChangeWindowMode(TRUE);

	// Dxlib���G���[���N�����Ă�������return��false��Ԃ�.
	if (DxLib_Init() == -1)
	{
		return false;
	}

	// fps���v�����邽�߂�
	mFps = new FPS();

	// 1�������Ԃ������Ȃ��N���X�̐���.
	// ��jUIManager::CreateInstance();
	//     ActorManager::CreateInstance();
	FishManager::CreateInstance();
	FishManager::CreatePool(1, 1, 1, 1);

	PoiManager::CreateInstance();

	// ��肪�Ȃ����true��Ԃ�.
	return true;
}

/// <summary>
/// �Q�[�����[�v.
/// </summary>
void GameManager::GameLoop()
{
	// ���[�v���񂷂��ǂ����̃t���O��true��������
	while (mRunningFlag)
	{
		// ���[�v�𔲂���ۂɎg�p������͏����֐�.
		ProcessInput();

		// ���݂̃V�[�������̃V�[����ۑ�����ϐ��ɕۑ�����.
		mReturnTag = mNowSceneClass->Updata();

		// ���̃V�[�������̃V�[���ƈ�����Ƃ�.
		if (mReturnTag != SceneBase::mNowSceneTag)
		{
			// ���̃V�[�����폜����.
			delete mNowSceneClass;

			// �V�����V�[���𐶐�����.
			CreateScene();

			// �ȉ��̏������΂���while���烋�[�v���Ȃ���.
			continue;
		}

		// �`�揈���֐�.
		DrawGame();

		// �X�V�����֐�.
		UpdateGame();
	}
}

/// <summary>
/// �N���X��}�l�[�W���[�̃������������.
/// </summary>
void GameManager::terminate()
{
	// 1�������Ԃ������Ȃ��N���X�̍폜.
	// ��jUIManager::DeleteInstance();
	//     ActorManager::DeleteInstance();
	FishManager::DeleteInstance();

	PoiManager::DeleteInstance();

	// ���̑��P�̂̃N���X�����ϐ��̍폜.
	delete mNowSceneClass;
	delete mFps;

	// Dxlib�̏I������.
	DxLib_End();
}

/// <summary>
/// mReturnTag���g�p�����V�����V�[���𐶐�����֐�.
/// </summary>
void GameManager::CreateScene()
{
	// ���̃^�O���^�C�g���V�[���̃^�O��������.
	if (mReturnTag == SceneBase::SceneTag::TitleTag)
	{
		// �^�C�g���N���X�𐶐�����.
		mNowSceneClass = new Title();
	}
	// ���̃^�O���`���[�g���A���V�[���̃^�O��������.
	else if (mReturnTag == SceneBase::SceneTag::TutorialTag)
	{
		// �`���[�g���A���N���X�𐶐�����.
		mNowSceneClass = new Tutorial();
	}
	// ���̃^�O���v���C�V�[���̃^�O��������.
	else if (mReturnTag == SceneBase::SceneTag::PlayTag)
	{
		// �v���C�N���X�𐶐�����.
		mNowSceneClass = new Play();
	}
	// ���̃^�O�����U���g�V�[���̃^�O��������.
	else if (mReturnTag == SceneBase::SceneTag::ResultTag)
	{
		// ���U���g�N���X�𐶐�����.
		mNowSceneClass = new Result();
	}
	else if (mReturnTag == SceneBase::SceneTag::ExitTag)
	{
		mNowSceneClass = new Exit();
	}
	else
	{
		// �O�̃V�[���^�O�����݂̃V�[���^�O�֑������.@@@
		mNowSceneClass->mNowSceneTag = mReturnTag;
	}
}

/// <summary>
/// ���[�v�𔲂���ۂɎg�p������͏����֐�.
/// </summary>
void GameManager::ProcessInput()
{
	// �E�B���h�E������ꂽ��
	// �܂���ESC�L�[�������ꂽ��
	// �܂��͌��݂̃V�[���^�O��ExitTag��������.
	if (ProcessMessage() == -1
		|| CheckHitKey(KEY_INPUT_ESCAPE)
		|| mNowSceneClass->mNowSceneTag == SceneBase::SceneTag::ExitTag)
	{
		// �Q�[�����[�v�𔲂��邽�߂Ƀt���O��false�ɂ���.
		mRunningFlag = false;
	}
	else
	{
		// ���݂̃V�[���ʂ̓��͏���.
		mNowSceneClass->Input();
	}
}

/// <summary>
/// �X�V����.
/// </summary>
void GameManager::UpdateGame()
{
	// deltaTime��fps�N���X����󂯎��.
	float deltaTime = mFps->GetDeltaTime();

	//----------------���ꂼ��̍X�V����---------------------

	// FishManager�̍X�V����
	FishManager::Update(deltaTime);
	//-------------------------------------

	PoiManager::Update(deltaTime);

	// fps�N���X���X�V����.
	mFps->Update();

}

/// <summary>
/// �`�揈��.
/// </summary>
void GameManager::DrawGame()
{
	// ��ʂ���x��������.
	ClearDrawScreen();

	//------------------���ꂼ��̕`�揈��---------------------

	// ���݂̃V�[����`�悷��.
	mNowSceneClass->Draw();

	//---------------------------------------

	// ���X�N���[���ɕ`�悵�����̂�\�ɕ\������.
	ScreenFlip();
}