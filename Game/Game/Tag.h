#pragma once

enum class Tag
{
	Begin,				// Tagの開始マーカー(Beginより手前に定義してはならない)

	Poi,
	Fish,
	FailureFish,
	RedFish,
	BlueFish,
	GoldFish,
	BlackFish,

	End                 // Tagの終了マーカー　（Endより後に定義してはならない）
};