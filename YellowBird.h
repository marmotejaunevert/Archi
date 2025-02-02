#pragma once
#include "Bird.h"
class YellowBird : public Bird
{
public:
	YellowBird(const float _radius);
public:
	virtual void Construct() override;
};

