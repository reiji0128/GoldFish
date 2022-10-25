#include "DxLib.h"
#include "GameManager.h"
#include "Title.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// �Q�[���N���X��`.
	GameManager gameMane;

	// �Q�[���S�̂̏������̌��ʂ�Ԃ��Btrue�Ȃ琬���Afalse�Ȃ玸�s.
	bool success = gameMane.Initialize();

	// �Q�[���S�̂̍ŏ��̃V�[���̐ݒ�.
	gameMane.SetFirstScene(new Title());

	// ���������������Ă�����.
	if (success)
	{
		// �Q�[�����[�v����.
		gameMane.GameLoop();
	}

	// �Q�[�����I����������.
	gameMane.terminate();

	// �v���O�����S�̂̏I��.
	return 0;
}