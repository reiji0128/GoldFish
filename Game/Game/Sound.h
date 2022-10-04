#pragma once

/// <summary>
/// Soundファイル
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
    /// コンストラクタ
    /// </summary>
    Sound();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Sound();

    /// <summary>
    /// 読み込み関数.
    /// </summary>
    /// <param name="imgName">読み取り専用のchar*型のファイルパス.</param>
    void Load(const char* soundName);

    /// <summary>
    /// 再生関数.
    /// </summary>
    void Play(int playTipe);

private:
    int mSoundHandle;		//サウンドの保存変数
};

