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
    // �~�`�̃Q�[�W��\������ϐ��̏�����.
    ,mCircePercent(0.0f)
{
    // �摜�n���h����ǂݍ���.
    mImgHandle = LoadGraph(fileName);

    // �摜�n���h���̃T�C�Y�̎擾.
    GetGraphSizeF(mImgHandle, &mScale.x, &mScale.y);
}

/// <summary>
/// �X�e�[�^�X�ʂ̕`��֐�.
/// </summary>
/// <param name="state">ViewState�^��enum class�̕ϐ�.</param>
void Image::Draw(ViewState state)
{
    // �X�e�[�^�X���ʏ�̎�.
    if (state == ViewState::Normal)
    {
        // �`�揈��.
        DrawGraph((int)mPos.x, (int)mPos.y, mImgHandle, true);
    }
    // �X�e�[�^�X���~�`�̃Q�[�W��̎�.
    else if (state == ViewState::CircleGauge)
    {
        // �~�`�̃Q�[�W��ۑ�����ϐ��̑��.
        mCircePercent += 0.3f;
        // �`�揈��.
        DrawCircleGaugeF(mPos.x, mPos.y, mCircePercent, mImgHandle, true);
    }
}