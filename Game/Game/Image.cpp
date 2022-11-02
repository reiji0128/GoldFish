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
    , mScale(Vector2::Zero)
    // �摜�n���h���ۑ��ϐ��̏�����.
    , mImgHandle(-1)
    // �`��̍ۂɎg�p����X�e�[�^�X��ۑ�����ϐ�.
    , mState(ViewState::None)
    // �~�`�̃Q�[�W��\������ϐ��̏�����.
    , mCirclePercent(0.0f)
    // �~�`�̃Q�[�W�𓮂����ׂ̕ϐ��̏�����.
    , mCirclePercentAdd(0.0f)
    // �~�`�̃Q�[�W�𓮂������ǂ����̕ϐ��̏�����.
    , mCircleMoveFlag(false)
{
    // �摜�n���h����ǂݍ���.
    mImgHandle = LoadGraph(fileName);

    // �摜�n���h���̃T�C�Y�̎擾.
    GetGraphSizeF(mImgHandle, &mScale.x, &mScale.y);
}

/// <summary>
/// �X�e�[�^�X�ʂ̕`��֐�.
/// </summary>
void Image::Draw()
{
    // �X�e�[�^�X���~�`�̃Q�[�W��̎�.
    if (mState == ViewState::CircleGauge
        && mCircleMoveFlag)
    {
        // �`�揈��.
        DrawCircleGaugeF(mPos.x, mPos.y, mCirclePercent, mImgHandle, true);
    }
    // ����ȊO�̎�.
    else
    {
        DrawGraph(mPos.x, mPos.y, mImgHandle, true);
    }
}