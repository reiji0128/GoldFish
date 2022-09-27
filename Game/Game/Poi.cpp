#include "Poi.h"
#include "Dxlib.h"
#include "FishManager.h"
#include <math.h>

/// <summary>
/// �R���X�g���N�^
/// </summary>
Poi::Poi(const int num)
	:mImage(0)
	,mFloatScale(1.0f)
	,mPadNum(0)
	,mInputX(0)
	,mInputY(0)
	,mSpeed(400.0f)
	,mAnimCounter(0)
	,mAnimNum(0)
	,mBonusCount(0)
	,mBonusCounter(0)
	,mPoiHP(24)
	,deadTime(0)
	,mScore(0)
{
	const char* scoopImgStr = NULL;
	const char* breakImgStr = NULL;
	if (num == 1)
	{
		scoopImgStr = "Img/Player/Scoop.png";
		breakImgStr = "Img/Player/Break.png";
		mPositionX = 480.0f;
		mPositionY = 810.0f;
		mPadNum = DX_INPUT_PAD1;
	}
	else if (num == 2)
	{
		scoopImgStr = "Img/Player/Scoop2.png";
		breakImgStr = "Img/Player/Break2,png";
		mPositionX = 1440.0f;
		mPositionY = 810.0f;
		mPadNum = DX_INPUT_PAD2;
	}

	mScaleX    = 128.0f;
	mScaleY    = 256.0f;
	mHalfScaleX = mScaleX / 2.0f;
	mHalfScaleY = mScaleY / 2.0f;
	mIsBonus      = false;
	mIsScoop      = false;
	mIsFirstFrame = false;
	mPrevInputA   = false;
	mAlive = true;
	LoadDivGraph(scoopImgStr, 5, 5, 1, (int)mScaleX, (int)mScaleY, mScoopImg);
	LoadDivGraph(breakImgStr, 5, 5, 1, (int)mScaleX, (int)mScaleY, mBreakImg);
	
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Poi::~Poi()
{
}

/// <summary>
/// �I�u�W�F�N�g�̍X�V����
/// </summary>
/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
void Poi::Update(float deltaTime)
{
	// �ړ�
	Move(deltaTime);

	// �ʒu����
	AdjustPosition();

	// �{�[�i�X
	BonusTime(deltaTime);

	// �d��
	Scoop(deltaTime);

	// �̗͊m�F
	CheckHP();

	// �|�C�̏C��
	PoiRepair(deltaTime);

}

/// <summary>
/// �`�揈��
/// </summary>
void Poi::Draw()
{
	DrawRotaGraph((int)mPositionX, (int)mPositionY, mFloatScale, 0, mImage, TRUE);
}

/// <summary>
/// �ړ�����
/// </summary>
/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
void Poi::Move(float deltaTime)
{
	// �X�e�B�b�N�̓��͏�Ԃ��擾
	GetJoypadAnalogInput(&mInputX, &mInputY, mPadNum);

	// �E�ɓ|��Ă�����
	if (mInputX > 0)
	{
		mPositionX += mSpeed * deltaTime;
	}

	// ���ɓ|��Ă�����
	if (mInputX < 0)
	{
		mPositionX -= mSpeed * deltaTime;
	}

	// ��ɓ|��Ă�����
	if (mInputY > 0)
	{
		mPositionY += mSpeed * deltaTime;
	}

	// ���ɓ|��Ă�����
	if (mInputY < 0)
	{
		mPositionY -= mSpeed * deltaTime;
	}
}

/// <summary>
/// �ʒu��������
/// </summary>
void Poi::AdjustPosition()
{
	if (mPositionX - (mHalfScaleX * mFloatScale) <= 0)
	{
		mPositionX = (mHalfScaleX * mFloatScale);
	}

	if (mPositionX + (mHalfScaleX * mFloatScale) >= 1920)
	{
		mPositionX = 1920 - (mHalfScaleX * mFloatScale);
	}

	if (mPositionY - (mHalfScaleY * mFloatScale) <= 0)
	{
		mPositionY = (mHalfScaleY * mFloatScale);
	}

	if (mPositionY >= 1080)
	{
		mPositionY = 1080;
	}
}

/// <summary>
/// �{�[�i�X�^�C������
/// </summary>
/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
void Poi::BonusTime(float deltaTime)
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
		mBonusCounter+=deltaTime;
	}
	else
	{
		mFloatScale = 1.0f;
	}

	if (mBonusCounter > 5.0f)
	{
		mBonusCounter = 0;
		mBonusCount = 0;
		mIsBonus = false;
	}
}

/// <summary>
/// �d������
/// </summary>
/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
void Poi::Scoop(float deltaTime)
{
	// �{�^����������Ă��Ȃ�������
	if ((GetJoypadInputState(mPadNum) & PAD_INPUT_3) == 0)
	{
		// �O�t���[���ŉ�����Ă��Ȃ����Ƃɂ���
		mPrevInputA = FALSE;
	}
	else
	{
		// �O�t���[���ŉ�����Ă��炸
		// �d���Ă��炸
		// �����Ă�����
		if (!mPrevInputA && !mIsScoop && mAlive)
		{
			// �d���Ă����Ԃɂ���
			mIsScoop = TRUE;
			// �d�����߂�1�t���[����
			mIsFirstFrame = TRUE;
			// �������̗̑͌���
			mPoiHP -= 3;
			// ������Ă��邱�Ƃɂ���
			mPrevInputA = TRUE;
		}
		if (mPoiHP > 0)
		{
			mAlive = true;
		}
		else
		{
			mAlive = false;
		}
		
	}

	// �|�C�������Ă��ċd���Ă���Ȃ�
	if (mAlive && mIsScoop)
	{
		// 1�t���[���ڂȂ�
		if (mIsFirstFrame)
		{
			// �A�j���[�V�����̃J�E���^������
			mAnimCounter = 0;
			mIsFirstFrame = FALSE;

			// �|�C�Ƌ����̓����蔻��𒲂ׂ�
			Coll();

		}
		mAnimNum = int(mAnimCounter * 8);
		mImage = mScoopImg[mAnimNum];
		if (mAnimNum >= 4)
		{
			mIsScoop = FALSE;
		}
	}
	else
	{
		mIsFirstFrame = TRUE;
	}
}

/// <summary>
/// �̗͊m�F����
/// </summary>
void Poi::CheckHP()
{
	if (!mIsScoop)
	{
		if (mPoiHP < 1)
		{
			mImage = mBreakImg[4];
		}
		else if (mPoiHP >= 1 && mPoiHP < 8)
		{
			mImage = mBreakImg[3];
		}
		else if (mPoiHP >= 8 && mPoiHP < 16)
		{
			mImage = mBreakImg[2];
		}
		else if (mPoiHP >= 16 && mPoiHP < 24)
		{
			mImage = mBreakImg[1];
		}
		else if (mPoiHP == 24)
		{
			mImage = mBreakImg[0];
		}
	}
}

/// <summary>
/// �X�R�A�v�Z��HP����
/// </summary>
/// <param name="tag">�����̎��</param>
void Poi::CalcScoreAndHP(Tag tag)
{
	// 1P���Ԃ��������d������
	// 2P�����������d������
	if ((tag == Tag::RedFish && mPadNum == DX_INPUT_PAD1) ||
		(tag == Tag::BlueFish && mPadNum == DX_INPUT_PAD2))
	{
		mScore += 10;
		mPoiHP -= 3;
		mBonusCount++;
	}
	// ���݂��̐F���d������
	else if ((tag == Tag::RedFish && mPadNum == DX_INPUT_PAD2) ||
		(tag == Tag::BlueFish && mPadNum == DX_INPUT_PAD1))
	{
		mPoiHP -= 4;
	}

	// ���̋������d������
	if (tag == Tag::GoldFish)
	{
		mScore += 20;
		mPoiHP -= 5;
	}

	// ���̋������d������
	if (tag == Tag::BlackFish)
	{
		mScore += 15;
		mPoiHP -= 4;
	}

	// �����ȊO���d������
	if (tag == Tag::FailureFish)
	{
		mPoiHP -= 6;
	}
}

/// <summary>
/// �|�C�̏C��
/// </summary>
/// <param name="deltaTime"></param>
void Poi::PoiRepair(float deltaTime)
{
	if (!mAlive)
	{
		deadTime += deltaTime;
	}

	if (deadTime > 3.0f)
	{
		deadTime = 0;
		mAlive = true;
		mPoiHP = 24;
	}
}

/// <summary>
/// �����蔻��
/// </summary>
void Poi::Coll()
{
	float pPosX   = mPositionX - 64.0f;
	float pPosY   = mPositionY;
	float pRadius = mHalfScaleX;


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

		if (vec <= pRadius + fRadius)
		{
			// �������Ă���
			CalcScoreAndHP(tmpFish.tag);
		}
		else
		{
			// �������Ă��Ȃ�
		}
	}
	
}
