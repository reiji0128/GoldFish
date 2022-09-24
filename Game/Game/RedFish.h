#pragma once
#include "Fish.h"

class RedFish : public Fish
{
public:
	RedFish(Tag tag);

	~RedFish();

	void UpdateObject(float deltaTime) override;

	void Draw();
};
