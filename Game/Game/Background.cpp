#include "Background.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Background::Background()
{
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Background::~Background()
{
}

/// <summary>
/// �X�V�֐�.
/// </summary>
void Background::Update()
{
}

/// <summary>
/// �`��֐�.
/// </summary>
void Background::Draw()
{
	// �`�揈��.
	DrawGraph(mPos.x, mPos.y, mImgHandle, true);
}