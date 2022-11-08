#pragma once

/// <summary>
/// Soundファイル
/// </summary>
enum SoundFile: unsigned int
{
    NullSound=0,
    SCOOP,

    MaxSoundNum
};

// 上記のenumクラスの順番で画像パスを保存する保存変数.
static const char* SoundName[SoundFile::MaxSoundNum] =
{
    "",
    "Sound/ScoopSE.mp3",
};

class Sound
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Sound(const char*fileName);

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Sound();

	/// <summary>
	/// 再生関数.
	/// </summary>
	void Play(int playTipe);

    /// <summary>
    /// 停止関数.
    /// </summary>
    void Stop();

private:
	int mSoundHandle;		//サウンドの保存変数
};

