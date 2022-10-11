#include "Sound.h"
#include<DxLib.h>

/// <summary>
/// コンストラクタ.
/// </summary>
Sound::Sound()
    :mSoundHandle(-1)
{
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
/// 読み込み関数.
/// </summary>
void Sound::Load(const char* soundName)
{
    mSoundHandle = LoadSoundMem(soundName);
}

/// <summary>
/// 描画関数.
/// </summary>
void Sound::Play(int playTipe)
{
    PlaySoundMem(mSoundHandle, playTipe, FALSE);
}