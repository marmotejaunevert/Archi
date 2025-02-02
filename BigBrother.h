#pragma once
#include "Bird.h"
class BigBrother : public Bird
{
public:
	BigBrother(const float _radius);
public:
	virtual void Construct() override;
};

