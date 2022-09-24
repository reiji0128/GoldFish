#pragma once
#include "Fish.h"

class BlueFish : public Fish
{
public:

	BlueFish(Tag tag);

	~BlueFish();

	void UpdateObject(float deltaTime) override;

	void Draw();
};