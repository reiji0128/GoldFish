#include "PoiBase.h"
#include "DxLib.h"
#include "FishManager.h"
#include <math.h>

/// <summary>
/// �R���X�g���N�^
/// </summary>
PoiBase::PoiBase()
    :mPosX(0)
    ,mPosY(0)
    ,mScaleX(128.0f)
    ,mScaleY(256.0f)
    ,mFloatScale(1.0f)
    ,mHalfScaleX(mScaleX/2)
    ,mHalfScaleY(mScaleY/2)
    ,mPadNum(0)
    ,mInputX(0)
    ,mInputY(0)
    ,mSpeed(400.0f)
    ,mImage(0)
    ,mBrokenImg(0)
    ,mBrokenImgF(0)
    ,mIsFlash(false)
    ,mIsScoop(false)
    ,mIsFirstFrame(false)
    ,mPrevInput(false)
    ,mAnimCounter(0)
    ,mAnimNum(0)
    ,mBonusCount(0)
    ,mBonusTimer(0)
    ,hp(24)
    ,mIsAlive(true)
    ,deadTime(0)
    ,mScore(0)
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
PoiBase::~PoiBase()
{
    // �摜�̔j��
    DeleteGraph(mImage);
    for (int i = 0; i < 5; i++)
    {
        DeleteGraph(mBreakImg[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        DeleteGraph(mScoopImg[i]);
    }
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
void PoiBase::Update(float deltaTime)
{
    Move(deltaTime);

    AdjustPos();

    Bonus(deltaTime);

    Scoop(deltaTime);

    CheckHP();

    Repair(deltaTime);

}

/// <summary>
/// �`�揈��
/// </summary>
void PoiBase::Draw()
{
    DrawRotaGraph((int)mPosX, (int)mPosY, mFloatScale, 0, mImage, TRUE);
}

/// <summary>
/// �ړ�����
/// </summary>
/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
void PoiBase::Move(float deltaTime)
{
    // �X�e�B�b�N�̓��͏�Ԃ��擾
    GetJoypadAnalogInput(&mInputX, &mInputY, mPadNum);

    // �E�ɓ|��Ă�����
    if (mInputX > 0)
    {
        mPosX += mSpeed * deltaTime;
    }

    // ���ɓ|��Ă�����
    if (mInputX < 0)
    {
        mPosX -= mSpeed * deltaTime;
    }

    // ��ɓ|��Ă�����
    if (mInputY > 0)
    {
        mPosY += mSpeed * deltaTime;
    }

    // ���ɓ|�ꂽ������
    if (mInputY < 0)
    {
        mPosY -= mSpeed * deltaTime;
    }
}

/// <summary>
/// �ʒu��������
/// </summary>
void PoiBase::AdjustPos()
{
    // ��ʍ��[�ɐڐG������
    if (mPosX < 0 + (mHalfScaleX * mFloatScale))
    {
        mPosX = 0 + (mHalfScaleX * mFloatScale);
    }

    // ��ʉE�[�ɐڐG������
    if (mPosX > 1920 - (mHalfScaleX * mFloatScale))
    {
        mPosX = 1920 - (mHalfScaleX * mFloatScale);
    }

    // ��ʏ�ɐڐG������
    if (mPosY < 0 + (mHalfScaleY * mFloatScale))
    {
        mPosY = 0 + (mHalfScaleY * mFloatScale);
    }

    // ��ʉ��ɐڐG������
    if (mPosY >= 1080)
    {
        mPosY = 1080;
    }
}

/// <summary>
/// �d������
/// </summary>
/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
void PoiBase::Scoop(float deltaTime)
{
    // �{�^����������Ă��Ȃ�������
    if ((GetJoypadInputState(mPadNum) & PAD_INPUT_3) == 0)
    {
        // �O�t���[���ŉ�����Ă��Ȃ����Ƃɂ���
        mPrevInput = false;
    }
    else
    {
        // �O�t���[���ł̓��͂��Ȃ��A�d���Ă��Ȃ���ԂŁA�����Ă�����
        if (!mPrevInput && !mIsScoop && mIsAlive)
        {
            // �d���Ă����Ԃ�ۑ�����
            mIsScoop = true;
            // 1�t���[���ڂł��邱�Ƃ�ۑ�����
            mIsFirstFrame = true;
            // ���͂��ꂽ���Ƃ�ۑ�����
            mPrevInput = true;
            // �������̗̑͌���
            hp -= 3;
        }
        if (hp > 0)
        {
            mIsAlive = true;
        }
        else
        {
            mIsAlive = false;
        }
    }

    // �����Ă��ċd���Ă���Ȃ�
    if (mIsAlive && mIsScoop)
    {
        // 1�t���[���ڂȂ�
        if (mIsFirstFrame)
        {
            // �A�j���[�V�����̃J�E���^������
            mAnimCounter = 0;
            mIsFirstFrame = false;

            // �����蔻��𒲂ׂ�
            //Coll();
        }
        mAnimCounter += deltaTime;
        mAnimNum = int(mAnimCounter * 12);
        mImage = mScoopImg[mAnimNum];
        if (mAnimNum >= 6)
        {
            mIsScoop = false;
        }
    }
    else
    {
        mIsFirstFrame = false;
    }
}

/// <summary>
/// �̗͊m�F����
/// </summary>
void PoiBase::CheckHP()
{
    if (!mIsScoop)
    {
        if (hp < 1)
        {
            mImage = mBreakImg[4];
        }
        else if (hp >= 1 && hp < 8)
        {
            mImage = mBreakImg[3];
        }
        else if (hp >= 8 && hp < 16)
        {
            mImage = mBreakImg[2];
        }
        else if (hp >= 16 && hp < 24)
        {
            mImage = mBreakImg[1];
        }
        else if (hp == 24)
        {
            mImage = mBreakImg[0];
        }
    }
}

/// <summary>
/// �C������
/// </summary>
/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
void PoiBase::Repair(float deltaTime)
{
    if (!mIsAlive)
    {
        deadTime += deltaTime;
    }

    if (deadTime > 3.0f)
    {
        deadTime = 0;
        mIsAlive = true;
        hp = 24;
    }
}

/// <summary>
/// �{�[�i�X����
/// </summary>
/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
void PoiBase::Bonus(float deltaTime)
{
    if (mBonusCount > 2)
    {
        mIsBonus = true;
    }
    else
    {
        mIsBonus = false;
    }

    if (mIsBonus)
    {
        mFloatScale = 2.0f;
        mBonusTimer += deltaTime;
    }
    else
    {
        mFloatScale = 1.0f;
    }

    if (mBonusTimer > 5.0f)
    {
        mBonusTimer = 0;
        mBonusCount = 0;
        mIsBonus = false;
    }
}

/// <summary>
/// �X�R�A�̌v�Z
/// </summary>
/// <param name="tag">�����̎��</param>
void PoiBase::CalcScore(Tag tag)
{
    // �����F�̋������d������
    if ((tag == Tag::RedFish) && mPadNum == DX_INPUT_PAD1 ||
        (tag == Tag::BlueFish && mPadNum == DX_INPUT_PAD2))
    {
        mScore += 10;
        hp -= 3;
        mBonusCount++;
    }

    // ���݂��̐F�̋������d������
    if ((tag == Tag::RedFish && mPadNum == DX_INPUT_PAD2) || 
        (tag == Tag::BlueFish && mPadNum == DX_INPUT_PAD1))
    {
        hp -= 4;
    }

    // ���̋������d������
    if (tag == Tag::GoldFish)
    {
        mScore += 20;
        hp -= 5;
    }

    // ���̋������d������
    if (tag == Tag::BlackFish)
    {
        mScore += 15;
        hp -= 4;
    }

    // �����ȊO���d������
    if (tag == Tag::FailureFish)
    {
        hp -= 6;
    }
}

/// <summary>
/// �����蔻��
/// </summary>
void PoiBase::Coll()
{
    float pPosX = mPosX - 64.0f;
    float pPosY = mPosY;
    float mRadius = mHalfScaleX;

    CollisionInfo tmpFish;
    for (int i = 0; i < 30; i++)
    {
        tmpFish = FishManager::GetCollisionInfo(i);

        float fPosX = tmpFish.pos.x;
        float fPosY = tmpFish.pos.y;
        float fRadius = 32.0f;

        float vecX = pPosX - fPosX;
        float vecY = pPosY - fPosY;
        float vec = sqrt(vecX * vecX + vecY * vecY);

        if (vec <= fRadius + fRadius)
        {
            CalcScore(tmpFish.tag);
        }
    }
}
