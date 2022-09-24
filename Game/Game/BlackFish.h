#pragma once
#include "Fish.h"

class BlackFish : public Fish
{
public:
	BlackFish(Tag tag);

	~BlackFish();

	void UpdateObject(float deltaTime) override;

	void Draw();
};
