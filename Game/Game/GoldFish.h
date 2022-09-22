#pragma once
#include "Fish.h"
#include "FishStateBase.h"


class GoldFish : public Fish
{
public:
	GoldFish(Tag tag);
	~GoldFish();

	void UpdateObject(float deltaTime) override;
	void Draw();
};
