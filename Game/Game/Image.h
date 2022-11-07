#pragma once
#include "Math.h"

/// <summary>
/// �摜�̕`�揈���ʂ̃X�e�[�^�X.
/// </summary>
enum class ViewState : unsigned short
{
    None = 0,                 // �摜�̕`�揈�����Ȃ���.
    Normal,                   // �摜�̕`�揈�������ʂɕ\������鎞.
    CircleGauge,              // �摜�̕`�揈�����~�`�ɕ\������鎞.
    Button,                   // �摜�̕`�揈�����{�^���Ƃ��ĕ\������鎞.

    MaxDrawState,             // �摜�̕`�揈���̃p�^�[����.
};

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
    virtual void Updata(float deltaTime, ViewState state) {};

    /// <summary>
    /// �X�e�[�^�X�ʂ̕`��֐��A���z�֐�.
    /// </summary>
    void Draw();

protected:
    Vector2 mPos;             // ���W�ۑ��ϐ�.
    Vector2 mScale;           // �摜�̑傫����ۑ�����ϐ�.
    int mImgHandle;           // �摜�n���h���ۑ��ϐ�.

    ViewState mState;         // �`��̍ۂɎg�p����X�e�[�^�X��ۑ�����ϐ�.

    double mCirclePercent;    // �~�`�̃Q�[�W���ǂ̒��x�܂ŕ\������̂���������ϐ�(double�^).
    double mCirclePercentAdd; // �~�`�̃Q�[�W�������Ă����l��ۑ�����ϐ�(double�^).
    bool mCircleMoveFlag;     // �~�`�̃Q�[�W�������Ă������ǂ����̃t���O�Atrue�Ȃ瓮��false�Ȃ瓮���Ȃ�.
    bool mCircleMaxFlag;      // �~�`�̃Q�[�W���ő�ɂȂ������ǂ����̃t���O�Atrue�Ȃ�360�x�`�悳��Ă���false�Ȃ�360�x�̕`��͂���Ă��Ȃ�.
    const double MPercentAdd; // �Q�[�W�𑝂₷�萔��(double�^).

public :// -------------------�Z�b�^�[�E�Q�b�^�[�֐�--------------------

    /// <summary>
    /// �摜�̍��W��ݒ肷��֐�.
    /// </summary>
    /// <param name="pos">Vector2�^�̕ϐ�.</param>
    void SetPosition(Vector2 pos) { this->mPos = pos; }

    /// <summary>
    /// ���݂̍��W��Ԃ�.
    /// </summary>
    /// <returns>Vector2�^�̍��W�ϐ���Ԃ�.</returns>
    Vector2 GetPosition() { return this->mPos; }

    /// <summary>
    /// ���݂̉摜�T�C�Y��Ԃ�.
    /// </summary>
    /// <returns>Vector2�^�̉摜�̑傫����ۑ����Ă���ϐ���Ԃ�.</returns>
    Vector2 GetScale() { return this->mScale; }

    /// <summary>
    /// �Q�[�W��������ʂ̎w�萔�̐ݒ�
    /// </summary>
    /// <param name="setNum">�Q�[�W���������(double�^)�A�ő�100.</param>
    void SetCirclePercent(double setNum) { this->mCirclePercent = setNum; }

    ///// <summary>
    ///// �Q�[�W��������ʂ̐ݒ�.
    ///// </summary>
    ///// <param name="add">double�^�̃Q�[�W�����ϐ�.</param>
    //void SetCirclePercentAdd(double add) { this->mCirclePercentAdd = add; }

    /// <summary>
    /// �Q�[�W��������ʂ̎擾.
    /// </summary>
    /// <returns>double�^�̃Q�[�W�����ϐ�.</returns>
    double GetCirclePercentAdd() { return this->mCirclePercentAdd; }

    /// <summary>
    /// �Q�[�W�������邩�ǂ����̃t���O�̐ݒ�.
    /// </summary>
    /// <param name="flag">bool�^�̕ϐ�.</param>
    void SetCircleFlag(bool flag) { this->mCircleMoveFlag = flag; }
};