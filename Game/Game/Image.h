#pragma once
#include "Math.h"

/// <summary>
/// �摜�֘A�N���X.
/// </summary>
class Image
{
public :
    /// <summary>
    /// �R���X�g���N�^.
    /// </summary>
    /// <param name="fileName">const char*�^�̉摜�t�@�C���p�X.</param>
    Image(const char* fileName);

    /// <summary>
    /// �f�X�g���N�^.
    /// </summary>
    virtual ~Image() {};

    /// <summary>
    /// �X�V�֐��A���z�֐�.
    /// </summary>
    /// <param name="deltaTime">float�^�̃f���^�^�C���̈���.</param>
    virtual void Updata(float deltaTime) = 0;

    /// <summary>
    /// �`��֐��A���z�֐�.
    /// </summary>
    virtual void Draw() = 0;

protected:
    Vector2 mPos;        // ���W�ۑ��ϐ�.
    Vector2 mScale;      // �摜�̑傫����ۑ�����ϐ�.
    int mImgHandle;      // �摜�n���h���ۑ��ϐ�.

public :// -------------------�Z�b�^�[�E�Q�b�^�[�֐�--------------------

    /// <summary>
    /// �摜�̍��W��ݒ肷��֐�.
    /// </summary>
    /// <param name="pos">Vector2�^�̕ϐ�.</param>
    void SetPosition(Vector2 pos)
    {
        this->mPos = pos;
    }

    /// <summary>
    /// ���݂̍��W��Ԃ�.
    /// </summary>
    /// <returns>Vector2�^�̍��W�ϐ���Ԃ�.</returns>
    Vector2 GetPosition()
    {
        return this->mPos;
    }

    /// <summary>
    /// ���݂̉摜�T�C�Y��Ԃ�.
    /// </summary>
    /// <returns>Vector2�^�̉摜�̑傫����ۑ����Ă���ϐ���Ԃ�.</returns>
    Vector2 GetScale()
    {
        return this->mScale;
    }
};