#pragma once

class PoiBase
{
public:
    /// <summary>
    /// �R���X�g���N�^.
    /// </summary>
    PoiBase();

    /// <summary>
    /// �f�X�g���N�^.
    /// </summary>
    virtual ~PoiBase();

    /// <summary>
    /// �X�V����.
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Update(float deltaTime);

    /// <summary>
    /// �`�揈��.
    /// </summary>
    void Draw();

    /// <summary>
    /// �ړ�����.
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Move(float deltaTime);

    /// <summary>
    /// �ʒu��������.
    /// </summary>
    void AdjustPos();

    /// <summary>
    /// �d������.
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Scoop(float deltaTime);

    /// <summary>
    /// �̗͌�������
    /// </summary>
    /// <param name="num">���������鐔�l</param>
    void DecHP(int num);

    void CheckHP();

    /// <summary>
    /// �C������.
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Repair(float deltaTime);

    /// <summary>
    /// �{�[�i�X����,
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    void Bonus(float deltaTime);

protected:

    float mPosX;
    float mPosY;

    float mScaleX;
    float mScaleY;

    float mFloatScale;

    float mHalfScaleX;
    float mHalfScaleY;

    int mPadNum;
    int mInputX;
    int mInputY;

    float mSpeed;

    int mImage;

    int mBreakImg[5];

    int mScoopImg[3];

    bool mIsScoop;

    bool mIsFirstFrame;

    bool mPrevInput;

    float mAnimCounter;
    int mAnimNum;

    bool mIsBonus;
    int mBonusCount;
    float mBonusCounter;

    bool mIsDead;

    float deadTime;

    int mScore;

};
