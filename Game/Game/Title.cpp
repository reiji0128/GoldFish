#include "Title.h"

Title::Title()
{
}

Title::~Title()
{
}

SCENE_TAG Title::Update(float deltaTime)
{
	mBg->Update();

	// �����Ń{�^���������ꂽ�Ƃ��Ƀv���C�V�[���ֈڍs���鏈��@@@

	// ����ȊO�̏ꍇ�͂��̃V�[����Ԃ�.
	return SCENE_TAG::NONE_TAG;
}

void Title::Draw()
{
	// �^�C�g���̔w�i��`��.
	mBg->Draw();
}