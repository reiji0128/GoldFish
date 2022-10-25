#include "Image.h"
#include "DxLib.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="fileName">const char*�^�̉摜�̃t�@�C���p�X.</param>
Image::Image(const char* fileName)
    // ���W�ۑ��ϐ��̏�����.
    :mPos(Vector2::Zero)
    // �摜�T�C�Y��ۑ�����ϐ��̏�����.
    ,mScale(Vector2::Zero)
    // �摜�n���h���ۑ��ϐ��̏�����.
    ,mImgHandle(-1)
{
    // �摜�n���h����ǂݍ���.
    mImgHandle = LoadGraph(fileName);

    // �摜�n���h���̃T�C�Y�̎擾.
    GetGraphSizeF(mImgHandle, &mScale.x, &mScale.y);
}
