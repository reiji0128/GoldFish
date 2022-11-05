#pragma once
#include "Tag.h"

class Sound;
class UI*ui;

class PoiBase
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    PoiBase();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~PoiBase();

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Update(float deltaTime);

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw();

protected:
    /// <summary>
    /// �ړ�����
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Move(float deltaTime);

    /// <summary>
    /// �ʒu��������
    /// </summary>
    void AdjustPos();

    /// <summary>
    /// �d������
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Scoop(float deltaTime);

    /// <summary>
    /// �̗͊m�F����
    /// </summary>
    void CheckHP();

    /// <summary>
    /// �C������
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Repair(float deltaTime);

    /// <summary>
    /// �{�[�i�X����
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Bonus(float deltaTime);

    /// <summary>
    /// �X�R�A�v�Z
    /// </summary>
    /// <param name="tag">�����̎��</param>
    void CalcScore(Tag tag);

    /// <summary>
    /// �����蔻��
    /// </summary>
    void Coll();

    // �ʒu
    float mPosX;
    float mPosY;

    // �X�P�[��
    float mScaleX;
    float mScaleY;

    // �X�P�[��(�ϓ��p)
    float mFloatScale;

    // �n�[�t�X�P�[���i�v�Z�p�j
    float mHalfScaleX;
    float mHalfScaleY;

    // �R���g���[���[�̓��͊֘A
    int mPadNum;
    int mInputX;
    int mInputY;

    // ���x
    float mSpeed;

    // �摜
    int mImage;

    // �j�ꍷ��
    int mBreakImg[5] = { -1 };

    // �d������
    int mScoopImg[6] = { -1 };

    int mBrokenImg;

    int mBrokenImgF;

    bool mIsFlash;

    // �d���Ă��邩�ǂ���
    bool mIsScoop;

    // 1�t���[���ڂ��ǂ���
    bool mIsFirstFrame;

    // �O�t���[���ł̓��͂��Ă������ǂ���
    bool mPrevInput;

    // �A�j���[�V�����p
    float mAnimCounter;
    int mAnimNum;

    // �{�[�i�X�p
    bool mIsBonus;
    int mBonusCount;
    float mBonusTimer;

    // �ϋv�l
    int hp;

    // �|�C�������Ă��邩�ǂ���
    bool mIsAlive;

    float deadTime;

    // �X�R�A
    int mScore[2] = { 0 };

protected:
    //Sound�̐���
    Sound* sound;
};
