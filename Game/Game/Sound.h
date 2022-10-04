#pragma once

/// <summary>
/// Sound�t�@�C��
/// </summary>
enum SoundFile : unsigned int
{
    NULL = 0,
    SCOOP,
};

class Sound
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Sound();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Sound();

    /// <summary>
    /// �ǂݍ��݊֐�.
    /// </summary>
    /// <param name="imgName">�ǂݎ���p��char*�^�̃t�@�C���p�X.</param>
    void Load(const char* soundName);

    /// <summary>
    /// �Đ��֐�.
    /// </summary>
    void Play(int playTipe);

private:
    int mSoundHandle;		//�T�E���h�̕ۑ��ϐ�
};

