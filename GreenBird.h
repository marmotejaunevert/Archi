#pragma once
#include "Bird.h"
class GreenBird : public Bird
{
public:
	GreenBird(const float _radius);
public:
	virtual void Construct() override;
};

