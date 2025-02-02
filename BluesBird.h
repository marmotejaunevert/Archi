#pragma once
#include "Bird.h"
class BluesBird : public Bird
{
public:
	BluesBird(const float _radius);
public:
	virtual void Construct() override;
};

