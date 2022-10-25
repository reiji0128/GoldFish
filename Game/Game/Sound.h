#pragma once

/// <summary>
/// Sound�t�@�C��
/// </summary>
enum SoundFile: unsigned int
{
    NullSound=0,
    SCOOP,

    MaxSoundNum
};

// ��L��enum�N���X�̏��Ԃŉ摜�p�X��ۑ�����ۑ��ϐ�.
static const char* SoundName[SoundFile::MaxSoundNum] =
{
    "",
    "Sound/ScoopSE.mp3",
};

class Sound
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Sound(const char*fileName);

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Sound();

	/// <summary>
	/// �Đ��֐�.
	/// </summary>
	void Play(int playTipe);

    /// <summary>
    /// ��~�֐�.
    /// </summary>
    void Stop();

private:
	int mSoundHandle;		//�T�E���h�̕ۑ��ϐ�
};

