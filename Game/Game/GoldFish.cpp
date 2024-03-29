#include "GoldFish.h"
#include <DxLib.h>
#include "Math.h"

GoldFish::GoldFish(Tag tag)
	:Fish(tag)
{
	// 画像の読み込み
	LoadDivGraph("Assets/GoldFish/GoldFish_Gold.png", 8, 8, 1, 128, 128, mGraphHandle);

	// 開始時の時間を取得
	mStartTime = GetNowCount() / 1000;
}

GoldFish::~GoldFish()
{
}

void GoldFish::UpdateObject(float deltaTime)
{
	// 正弦波を使った移動処理
	MoveSinWave();

	// 画面外に出たら状態を非アクティブに変更
	if (OverLimitPos())
	{
		mNowState = State::Inacive;
	}
}

void GoldFish::Draw()
{
	// 現在のカウンタからアニメーションの表示するハンドルを算出
	mNowCount = GetNowCount();
	mAnimationCount = mNowCount / 120 % 8;

	// 画像の表示
	DrawRotaGraph(mPosition.x, mPosition.y, 1.0, mAngle, mGraphHandle[mAnimationCount], true);
}

