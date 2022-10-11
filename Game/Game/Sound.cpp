#include "Sound.h"
#include<DxLib.h>

/// <summary>
/// �R���X�g���N�^.
/// </summary>
Sound::Sound()
    :mSoundHandle(-1)
{
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
/// �ǂݍ��݊֐�.
/// </summary>
void Sound::Load(const char* soundName)
{
    mSoundHandle = LoadSoundMem(soundName);
}

/// <summary>
/// �`��֐�.
/// </summary>
void Sound::Play(int playTipe)
{
    PlaySoundMem(mSoundHandle, playTipe, FALSE);
}