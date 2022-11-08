#include "Sound.h"
#include<DxLib.h>

/// <summary>
/// コンストラクタ.
/// </summary>
Sound::Sound(const char* fileName)
    :mSoundHandle(-1)
{
    //サウンド読み込み
    mSoundHandle = LoadSoundMem(fileName);
}

/// <summary>
/// デストラクタ.
/// </summary>
Sound::~Sound()
{
    //サウンドハンドルが-1じゃなかったら
    if (mSoundHandle != -1)
    {
        //サウンドをメモリ上から削除する
        DeleteSoundMem(mSoundHandle);
    }
    mSoundHandle = -1;
}

/// <summary>
/// 再生関数.
/// </summary>
void Sound::Play(int playTipe)
{
    PlaySoundMem(mSoundHandle, playTipe, FALSE);
}

/// <summary>
/// 停止関数.
/// </summary>
void Sound::Stop()
{
    StopSoundMem(mSoundHandle);
}