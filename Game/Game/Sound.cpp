#include "Sound.h"
#include<DxLib.h>

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Sound::Sound(const char* fileName)
    :mSoundHandle(-1)
{
    //�T�E���h�ǂݍ���
    mSoundHandle = LoadSoundMem(fileName);
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
Sound::~Sound()
{
    //�T�E���h�n���h����-1����Ȃ�������
    if (mSoundHandle != -1)
    {
        //�T�E���h���������ォ��폜����
        DeleteSoundMem(mSoundHandle);
    }
    mSoundHandle = -1;
}

/// <summary>
/// �Đ��֐�.
/// </summary>
void Sound::Play(int playTipe)
{
    PlaySoundMem(mSoundHandle, playTipe, FALSE);
}

/// <summary>
/// ��~�֐�.
/// </summary>
void Sound::Stop()
{
    StopSoundMem(mSoundHandle);
}