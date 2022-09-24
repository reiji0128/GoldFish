#include "FPS.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ.
/// </summary>
FPS::FPS()
    // フレームレートの最高値の初期化.
	: MSetFps(60)
	// 1フレームにかける時間.
	, MOneFrameTickCount(1000 / MSetFps)
	// １つ前のフレームのかかった時間.
	, mBeforeTickCount(0)
	// 現在のフレームのかかった時間.
	, mDeltaTime(0)
{
}

/// <summary>
/// 更新処理.
/// </summary>
void FPS::Update()
{
	// fpsが基準値より大きくならないようにする処理.
	Wait();

	// デルタタイムの計算.
	mDeltaTime = (GetNowCount() - mBeforeTickCount) / 1000.0f;

	// デルタタイムを制御.
	if (mDeltaTime >= 0.10f)
	{
		// デルタタイムを0.10fに設定する.
		mDeltaTime = 0.10f;
	}

	// 前フレームとしてここまでかかった時間を保存する.
	mBeforeTickCount = GetNowCount();
}

/// <summary>
/// fpsが基準値より大きくならないようにする関数.
/// </summary>
void FPS::Wait()
{
	// 現在値が1フレームにかける時間を超えるまで繰り返す
	while (GetNowCount() < mBeforeTickCount + MOneFrameTickCount);
}
